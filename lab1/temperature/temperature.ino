    /* temperature
    *
    * read temperature from TMP36 sensor
    *
    */
      // Analog input pin
     
void setup() {
    // put your setup code here, to run once:
  
    
    Serial.begin(9600);
  
    }
    
void loop() {
     /* Serial.write("@");
      Serial.write(0x04);
      Serial.write(millis());
      Serial.write(2);
      Serial.write("\r");*/
      
     // Serial.write("@");
      //Serial.write(0x04);
      long b = millis();
      //Serial.println(b);
      long lowestb = b & 0xff;
      long sectolowb = b >> 8;
      sectolowb = sectolowb & 0xff;
      long sectohigh = b >> 16;
      sectohigh = sectohigh & 0xff;
      long highestb = b >> 24;
      Serial.write(highestb);
      Serial.write(sectohigh);
      Serial.write(sectolowb);
      Serial.write(lowestb);      

      /*int a = 260;
      int lowa = a & 0xff;
      int higha = a>>8;
      Serial.write(higha);
      Serial.write(lowa);
     Serial.write("\r");*/
      
   delay(1000);
    }
