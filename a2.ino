//Code for Magic Flute sound visualization project. Written by Yanyi Wang.
//Acknowlegement:   Thanks for guidence and support from Nathan and Chester Yen 
//Reference : Tutorial on DIY TECH TUBE https://youtu.be/gQ3qVFU4RZk

#include <FastLED.h>

#define LED_PIN    7
#define NUM_LEDS   144 //Enter number of LEDS
int r,g,b;

CRGB leds[NUM_LEDS];

//int historyValue[500];
//int currPos=0;
//int frameCount=0;

void setup() {

  FastLED.addLeds< WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
    pinMode(A0,INPUT);
    Serial.begin(9600);
    
//  for (int i = 0; i < 500; i++) 
//  {
//    historyValue[i] = 0;
//  }
}

void loop() {
int val = analogRead(A0);
Serial.println(val);  

//historyValue[currPos] = val;
//currPos++;
//if(currPos>500)
//   currPos = 0;
//frameCount++;
//if(frameCount < 500)
//   return;
//
//double averageValue = 0;
//for (int i = 0; i < 500; i++) 
//{
//  averageValue += historyValue[i];
//}
//averageValue /= 500;

//Serial.println(averageValue); 
   
int j;
j=(350-val)/3;// Change Sensitivity
if(j<0)
j= -j;
if(j<72)
{ 
 // Serial.println("j=");
 // Serial.println(j);
  for (int i = 0; i < 144; i++) 
  {
     leds[i] = CRGB ( 0, 0, 0);
      //FastLED.show();
  }
  for (int i = 0; i <= j; i++) {
   if(i<30)
   {
    r=46;
    g=173;
    b=226;}
    else if(i<50)
    { r=174;
    g=214;
    b=241;}
    else
    { r=214;
    g=234;
    b=248;}
      
    leds[72-i] = CRGB ( r, g, b);
    leds[72+i] = CRGB ( r, g, b);
    Serial.println("hi");
 
    
    
  }
    FastLED.show();

  }
}
  
