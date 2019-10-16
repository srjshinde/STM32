#include "stm32f10x.h"
#include "adc.h"
#include "sw_delay.h"

int adc_value = 0;

void ADCenable(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN | RCC_APB2ENR_ADC1EN | RCC_APB2ENR_AFIOEN; //enabling ADC clock, interrupt enable, 
	RCC->CFGR |= RCC_CFGR_ADCPRE_DIV4;// ADC clock = 12 MHz, maximum is 14, but there is no divider for that freq (72MHz / 6 = 12MHz). works with div6 too
	//while clock for port A and B is enabled down below
	GPIOB->CRL &= ~(GPIO_CRL_CNF0_0|GPIO_CRL_CNF0_1|GPIO_CRL_MODE0_0|GPIO_CRL_MODE0_1); // pin A0 is analog input
	

	//ADC1->CR1 |=ADC_CR1_EOCIE;   //ADC interrupt enabled
	//NVIC_EnableIRQ(ADC1_2_IRQn); //interrupt enabled
	
	//ADC1->SMPR2 |= ADC_SMPR2_SMP8_0;//|ADC_SMPR2_SMP8_1|ADC_SMPR2_SMP8_2;
	ADC1->SQR3 |= ADC_SQR3_SQ1_3; //for B0 in sequence 1, channel 8, it is 0b1000 = 8 (IN8)
	//ADC1->SQR3 |=8; // alternative way of setting the same thing as above

	ADC1->CR2 &= ~ADC_CR2_ALIGN; //data is right aligned (0bxxxx111111111111)

	ADC1->CR2 |= ADC_CR2_ADON | ADC_CR2_CONT; //ADC converter is on
	delay(10); //alow ADC to stabilize - 1 mS, but my delay is not exactly 1 mS, it is much shorter...
  ADC1->CR2 |= ADC_CR2_CAL;
	delay(10); //it is better to leave some time, just few clock cycles...
	ADC1->CR2 |= ADC_CR2_ADON; //not sure it requires to call it again?
	delay(10); //After first ADON, ADC is just set, then second time ADC is actually enabled
}

/* For some unknown reason, DSP does not work if algorithm is included into IRQ handler, so NVIC is disabled for this IRQ */

/*void ADC1_2_IRQHandler(void)
{ 
	  if (ADC1->SR & ADC_SR_EOC) 
	{
    adc_value=ADC1->DR;
  }	
} 
*/

int adc(void)
{
	int adc=0;
	ADC1->CR2 |=ADC_CR2_SWSTART;
	//if(ADC1->SR & ADC_SR_EOC)
	//while(!(ADC1->SR & ADC_SR_EOC));
	adc=ADC1->DR;
	return adc;
}
