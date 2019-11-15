#include <Adafruit_NeoPixel.h>

#include <Adafruit_DRV2605.h>
//NEOPIXELS INITIALIZATION
// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        6 // On Trinket or Gemma, suggest changing this to 1
int pin         =  6; 
// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 24 // Popular NeoPixel ring size
int numPixels   = 24; // Popular NeoPixel ring size
int pixelFormat = NEO_GRB + NEO_KHZ800;
Adafruit_NeoPixel *pixels;
#define DELAYVAL 300 // Time (in milliseconds) to pause between pixels

//MOTOR VIBRATION CONTROLLER
Adafruit_DRV2605 drv;

void setup() {
  // put your setup code here, to run once:
pixels = new Adafruit_NeoPixel(numPixels, pin, pixelFormat);
pixels->begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
pixels->setBrightness(100);

  Serial.begin(9600);//open serial port to communicate with DRV
  Serial.println("DRV test");
  drv.begin(); //vibration control
  
  drv.selectLibrary(1);
  drv.setMode(DRV2605_MODE_INTTRIG); 


drv.setWaveform(0, 54);  // 
drv.setWaveform(1, 92);  // 
drv.setWaveform(2, 121);  // 
drv.setWaveform(3, 117);  // 
//drv.setWaveform(4, 93);  // 
drv.setWaveform(5, 92);  // 
drv.setWaveform(6, 0);  // 

}

uint8_t effect = 0;

void loop() {
  // put your main code here, to run repeatedly:
drv.go();
  Serial.print("Effect # "); Serial.println(effect);
   pixels->clear(); // Set all pixel colors to 'off'
   for(int i=0; i<numPixels; i++)
 pixels->setPixelColor(i, pixels->Color(100, 100, 0));
 pixels->setBrightness(20);
  pixels->show();   // Send the updated pixel colors to the hardware.
drv.go();
delay(600);
colorWipeFade(pixels->Color(0, 40, 200) , 20);
pixels->setBrightness(30);
pixels->show();
delay(300); // Pause before next pass through loop
pulseBrightness();
delay(500); // Pause before next pass through loop 
drv.go();
delay(600);
colorWipeFade(pixels->Color(20, 140, 220) , 20); 
pulseBrightness();
drv.go();
colorWipeFade(pixels->Color(10, 85, 175) , 20);
delay(200); 
drv.go();
delay(600);
pulseBrightness();
drv.go();
delay(600);
colorWipeFade(pixels->Color(75, 100, 175) , 20); 
delay(300); 
pixels->setBrightness(20);
pixels->show();
pulseBrightness();
}

void colorWipeFade(uint32_t color, int wait) {
  for(int i=0; i<pixels->numPixels(); i++) { // For each pixel in strip...
    pixels->setPixelColor(i, color);         //  Set pixel's color (in RAM)
    pixels->show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}

 void pulseBrightness()
 {
  pixels->setBrightness(30);
pixels->show();
delay(100); 
pixels->setBrightness(25);
pixels->show();
delay(100); 
pixels->setBrightness(20);
pixels->show();
delay(100); 
pixels->setBrightness(15);
pixels->show();
delay(100); 
pixels->setBrightness(10);
pixels->show();
delay(100); 
pixels->setBrightness(5);
pixels->show();
delay(100); 

pixels->setBrightness(5);
pixels->show();
delay(1000); // Pause before next pass through loop  
pixels->setBrightness(5);
pixels->show();
delay(100); 
pixels->setBrightness(10);
pixels->show();
delay(100); 
pixels->setBrightness(15);
pixels->show();
delay(100); 
pixels->setBrightness(20);
pixels->show();
delay(100); 
pixels->setBrightness(25);
pixels->show();
delay(100); 
pixels->setBrightness(30);
pixels->show();
delay(500); // Pause before next pass through loop 
 }
