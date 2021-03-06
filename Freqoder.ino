int LEDpin = 6;       //LED digital pin #
int brightness = 0;    //how bright the LED is
int fadeAmount = 30;   //how many points to fade the LED by
int signalCount = 0;   //
void setup() {
  //init. LED
  Serial.begin(9600);
  pinMode(LEDpin, OUTPUT);
}

void loop() {
  //begin LED signaling DIGITAL
  signalCount++;
  if(signalCount <= 3){
    analogWrite(LEDpin, 255); //TURN on LED
    delay(1000);
    analogWrite(LEDpin, 0); //TURN off LED
    delay(1000);
  }
  else if(signalCount <= 7){
    delay(2000);
    analogWrite(LEDpin, brightness);
    // change the brightness for next time through the loop:
    brightness = brightness + fadeAmount;
    // reverse the direction of the fading at the ends of the fade:
    if (brightness == 0 || brightness == 255) {
      fadeAmount = -fadeAmount ;
    }
  // wait for 30 milliseconds to see the dimming effect
  }
  else{
    signalCount = 0;  
  }
}
#   F r e q o d e r  
 