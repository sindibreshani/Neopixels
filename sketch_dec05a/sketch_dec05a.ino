#include <Adafruit_NeoPixel.h>


#ifdef __AVR__
  #include <avr/power.h>
#endif


#define PIN            8

#define NUMPIXELS      8
int potPin = A1;
int val = 0;
int colorVal = 0;
int reading = 0;
int x;
int prevVal = 0;
int switchPin = 6;
boolean lastBtn = LOW;
boolean NeopixelColor = false;
boolean lastButton = LOW;
int photocellPin = A5;     // the cell and 10K pulldown are connected to a0
int photocellReading;

//
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 500; 

void setup() {
  pinMode(potPin, INPUT);
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  strip.begin(); // This initializes the NeoPixel library.
}



void loop() {

 photocellReading = analogRead(photocellPin);  
 int sensorValue = map(photocellReading, 200, 700, 0, 8);
 
  for ( x = 0; x < 8; x++) {
    if( x < sensorValue) {
       strip.setPixelColor(x,random(0,255), random(0,255), random(0,255));
    } else {
      strip.setPixelColor(x,0, 0, 0);
    }
  }
    
  strip.show();
 //delay();
}

  /*reading = analogRead(potPin);
  val = (reading/1024.0) * 13;
  colorVal = (reading/1024.0) * 255;
  
  if (digitalRead(switchPin) == HIGH && lastButton == LOW)
  {
    delay(250); // Account for contact debounce
    NeopixelColor = !NeopixelColor;
    
  }
  
  if (NeopixelColor == false)
  {
    // Neopixel LED number code
    strip.setBrightness(20);
    if (val != prevVal)
    {
      for ( x = 0; x < val; x++) 
      {
        strip.setPixelColor(x,random(0,255), random(0,255), random(0,255));
      }
      for (x=val; x<13; x++) 
      { 
        strip.setPixelColor(x,0,0,0);
        strip.show();
      }
      prevVal = val;
    }
    else
    {
      strip.show();
    }
    
  }
  else
  {
    // Neopixel Color code
    for (x=0; x < prevVal; x++)
    {
      strip.setPixelColor(x, strip.Color(random(0,255), random(0,255), random(0,255)));
      strip.show();
    }
    

  }
}

  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.


    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
   // pixels.setPixelColor(i, pixels.Color(200,0,100));
   
 //for(int i=0;i<8;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
  // pixels.setPixelColor(i, pixels.Color(random(0,255), random(0,255), random(0,255))); // Moderately bright green color.

    //pixels.show(); // This sends the updated pixel color to the hardware.

    //delay(300); // Delay for a period of time (in milliseconds).

 // }
//}*/
