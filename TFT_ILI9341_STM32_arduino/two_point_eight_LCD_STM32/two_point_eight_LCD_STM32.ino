#include <Adafruit_GFX.h>
#include <gfxfont.h>

#include "Adafruit_ILI9341_8bit_STM.h"

#include <stdint.h>
#include "TouchScreen.h"

//#include <Fonts\FreeSans12pt7b.h>
//#include <Fonts\FreeMono24pt7b.h>

#include <Fonts\FreeSansBold9pt7b.h>
#include <Fonts\FreeSans12pt7b.h>
#include <Fonts\FreeMono24pt7b.h>

unsigned long previousMillis = 0;  
const long interval = 15000;    

/*#define LCD_CS PA3 
#define LCD_CD PA2
#define LCD_WR PA1
#define LCD_RD PA0 
#define LCD_RESET PB1 */

#define TS_MINX 430
#define TS_MINY 3630
#define TS_MAXX 3600
#define TS_MAXY 320

#define YP PB1
#define XM PB0
#define YM PA1
#define XP PA0

#define GBLUE   0x5E59
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define GREY    0xD69A //CE59
String state;

//Adafruit_TFTLCD_8bit_STM32 tft;

Adafruit_ILI9341_8bit_STM tft = Adafruit_ILI9341_8bit_STM();

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

void setup() {
   Serial1.begin(9600);
   //tft.reset();
   tft.begin();
   tft.setRotation(0);
   tft.fillScreen(WHITE);
   tft.fillRect(0,0,240,320,WHITE);
   tft.setFont(&FreeMono24pt7b);
   tft.setTextColor(GBLUE);
   tft.setCursor(24,40);
   tft.setTextSize(1);
   tft.print("GABRIEL");
   tft.setFont(&FreeSans12pt7b);
   tft.setTextColor(BLACK);
   tft.setCursor(13,64);
   tft.setTextSize(1);
   tft.print("ELECTRONICALLY");
   tft.setCursor(38,84);
   tft.print("ADJUSTABLE");
   tft.setCursor(38,104);
   tft.print("SUSPENSION");
   tft.fillRect(50,150, 150,60, WHITE);
   tft.drawRect(50,150, 150,60, BLUE);
   tft.setCursor(60,185);
   tft.setFont(&FreeSansBold9pt7b);
   tft.print("CONNECTING");
   delay(2000);
   while(1){
   //if (Serial1.available())
   if (1){
    Serial1.println("aa gaya!1");
    tft.fillRect(50,150, 150,60, WHITE);
    tft.drawRect(50,150, 150,60, BLUE);
    tft.setCursor(63,185);
    tft.print("CONNECTED");
    tft.setTextColor(BLUE);
    tft.setFont(&FreeMono24pt7b);
    tft.setCursor(20,143);
    tft.print("X");
    tft.fillRect(32,105, 25,40, WHITE);
    tft.setCursor(27,143);
    tft.print("B");
    tft.fillRect(25,105, 8,4, WHITE);
    tft.fillRect(25,142, 8,4, WHITE);
    delay(2000);
    tft.fillRect(50,150, 150,60, WHITE);
    break;
   }
   }/*
   tft.setTextColor(BLUE);
   tft.setFont(&FreeMono24pt7b);
   tft.setCursor(20,143);
   tft.print("X");
   tft.fillRect(32,105, 25,40, WHITE);
   tft.setCursor(27,143);
   tft.print("B");
   tft.fillRect(25,105, 8,4, WHITE);
   tft.fillRect(25,142, 8,4, WHITE);*/
   tft.setTextColor(BLACK);
   tft.setFont(&FreeSans12pt7b);
   tft.setCursor(85,144);
   tft.print("FRONT");
   tft.setCursor(85,230);
   tft.print("REAR");
   tft.setFont(&FreeSansBold9pt7b);
   tft.setTextSize(1);
   frblank();
   reblank();
}

void loop() {
  TSPoint p = ts.getPoint();
  
  if (p.z > ts.pressureThreshhold) {
   p.x = map(p.x, TS_MAXX, TS_MINX, 0, 240);
   p.y = map(p.y, TS_MAXY, TS_MINY, 0, 320);
    Serial1.print("X = "); Serial1.print(p.x);
     Serial1.print("\tY = "); Serial1.print(p.y);
     Serial1.print("\tPressure = "); Serial1.println(p.z);
     delay(100);
     
     pinMode(XM, OUTPUT);
     pinMode(YP, OUTPUT); 
   if(p.x>10 && p.x<105 && p.y>148 && p.y<208 ){
     Serial1.write("11110\n");
     frsports();
     feed();
    }
   if(p.x>135 && p.x<235 && p.y>148 && p.y<208 ){
     Serial1.write("11120\n");
     frnormal();
     feed();
      } 
   if(p.x>10 && p.x<105 && p.y>241 && p.y<291 ){
     resports();
     feed();
    }
   if(p.x>135 && p.x<235 && p.y>241 && p.y<309 ){
     renormal();
     feed();
      } 
   
  }
}
  void frsports(){
     
     tft.fillRoundRect(10,155,95,50,5,GREEN);
     tft.fillRoundRect(135,155,97,50,5,GREY);
     tft.setCursor(27,183);
     tft.print("SPORT");
     tft.setCursor(138,183);
     tft.print("COMFORT");

     } 
 void frnormal(){  
     tft.fillRoundRect(10,155,95,50,5,GREY);
     tft.fillRoundRect(135,155,97,50,5,GREEN);
     tft.setCursor(27,183);
     tft.print("SPORT");
     tft.setCursor(138,183);
     tft.print("COMFORT");
 }
 void resports(){
  
     tft.fillRoundRect(10,241, 95,50,5, GREEN);
     tft.fillRoundRect(135,241, 97,50,5, GREY);
     tft.setCursor(27,269);
     tft.print("SPORT");
     tft.setCursor(138,269);
     tft.print("COMFORT");
    
 }
 void renormal(){

     tft.fillRoundRect(10,241, 95,50,5, GREY);
     tft.fillRoundRect(135,241, 97,50,5, GREEN);
     tft.setCursor(27,269);
     tft.print("SPORT");
     tft.setCursor(138,269);
     tft.print("COMFORT");
    
 }
 void frblank(){
     
     tft.fillRoundRect(10,155,95,50,5,GREY);
     tft.fillRoundRect(135,155,97,50,5,GREY);
     tft.setCursor(27,183);
     tft.print("SPORT");
     tft.setCursor(138,183);
     tft.print("COMFORT");
     
    
 }
 void reblank(){

     tft.fillRoundRect(10,241, 95,50,5, GREY);
     tft.fillRoundRect(135,241, 97,50,5, GREY);
     tft.setCursor(27,269);
     tft.print("SPORT");
     tft.setCursor(138,269);
     tft.print("COMFORT");
    
 }
 
 void feed(){
  unsigned long currentMillis = millis();
  previousMillis = currentMillis;
 while(1){
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    error();
    while(1){}
  }
  
  if (Serial1.available()){
   state = Serial1.read(); 
   delay(2); 
   //myGLCD.print(state,8,104);
   if(state == "#0001"||state == "#0010"){ 
    com_process();
    }
    if(state == "#0011"||state == "#2200"){ 
    com_compl();
    delay(2000);
    tft.fillRect(0,150, 240,60, WHITE);
    frnormal();
    break;
    }
   if(state == "#0100"||state == "#1000"){ 
    com_process();
   }
   if(state == "#1100"||state == "#0022"){ 
    com_compl();
    delay(2000);
    tft.fillRect(0,150, 240,60, WHITE);
    frsports();
    break;
    }
   if(state == "#3300"){ 
    error();
    delay(5000);
    tft.fillRect(0,150, 240,60, WHITE);
    frblank();
    break;
    }
   if(state == "#0033"){ 
    error();
    delay(5000);
    tft.fillRect(0,150, 240,60, WHITE);
    frblank();
    break;
     }
    if(state == "#4444"){ 
    error();
    delay(5000);
    tft.fillRect(0,150, 240,60, WHITE);
    frblank();
    break;
    }
   if(state == "#5555"){ 
    try_again();
    delay(3000);
    tft.fillRect(0,150, 240,60, WHITE);
    frblank();
    break;
    }
  }
}
}

 void com_process(){
  
     tft.fillRect(50,150, 150,60, WHITE);
     tft.drawRect(50,150, 150,60, BLUE);
     tft.setCursor(52,185);
     tft.setFont(&FreeSans12pt7b);
     tft.print("IN PROCESS");
     tft.setFont(&FreeSansBold9pt7b);
    // tft.fillRoundRect(135,241, 97,50,5, GREY);
    /*tft.setCursor(27,269);
     tft.print("SPORT");
     tft.setCursor(138,269);
     tft.print("COMFORT");*/
   }
  void com_compl(){
     tft.fillRect(50,150, 150,60, WHITE);
     tft.drawRect(50,150, 150,60, BLUE);
      tft.setCursor(52,185);
     tft.setFont(&FreeSans12pt7b);
     tft.print("COMPLETED");
     tft.setFont(&FreeSansBold9pt7b);
    /*tft.setCursor(27,269);
     tft.print("SPORT");
     tft.setCursor(138,269);
     tft.print("COMFORT");*/
 }
 
void spo_process(){

     tft.fillRoundRect(30,180, 150,60,5, GREY);
    // tft.fillRoundRect(135,241, 97,50,5, GREY);
    /*tft.setCursor(27,269);
     tft.print("SPORT");
     tft.setCursor(138,269);
     tft.print("COMFORT");*/
   }
  void spo_compl(){

     tft.fillRoundRect(30,180, 150,60,5, GREY);
    // tft.fillRoundRect(135,241, 97,50,5, GREY);
    /*tft.setCursor(27,269);
     tft.print("SPORT");
     tft.setCursor(138,269);
     tft.print("COMFORT");*/
 }

   void com_error(){

     tft.fillRoundRect(30,180, 150,60,5, GREY);
    // tft.fillRoundRect(135,241, 97,50,5, GREY);
    /*tft.setCursor(27,269);
     tft.print("SPORT");
     tft.setCursor(138,269);
     tft.print("COMFORT");*/
 }
 
void spo_error(){

     tft.fillRoundRect(30,180, 150,60,5, GREY);
    // tft.fillRoundRect(135,241, 97,50,5, GREY);
    /*tft.setCursor(27,269);
     tft.print("SPORT");
     tft.setCursor(138,269);
     tft.print("COMFORT");*/
   }
 
void error(){

     tft.fillRect(50,150, 150,60, WHITE);
     tft.drawRect(50,150, 150,60, BLUE);
      tft.setCursor(52,185);
     tft.setFont(&FreeSans12pt7b);
     tft.print("     ERROR  ");
     tft.setFont(&FreeSansBold9pt7b);
    // tft.fillRoundRect(135,241, 97,50,5, GREY);
    /*tft.setCursor(27,269);
     tft.print("SPORT");
     tft.setCursor(138,269);
     tft.print("COMFORT");*/
 }
 
void try_again(){

     tft.fillRect(50,150, 150,60, WHITE);
     tft.drawRect(50,150, 150,60, BLUE);
     tft.setCursor(52,185);
     tft.setFont(&FreeSans12pt7b);
     tft.print("  TRY AGAIN   ");
     tft.setFont(&FreeSansBold9pt7b);
    // tft.fillRoundRect(135,241, 97,50,5, GREY);
    /*tft.setCursor(27,269);
     tft.print("SPORT");
     tft.setCursor(138,269);
     tft.print("COMFORT");*/
   }
