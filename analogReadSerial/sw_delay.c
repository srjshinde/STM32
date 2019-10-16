
// Time loop optimized to produce 1ms software delay

void delay(int time_in_ms)
{
	int i,j;
	for( i=0; i< time_in_ms; i++)
	{
		for( j=0; j< 0x2AFF; j++);
	}
}
