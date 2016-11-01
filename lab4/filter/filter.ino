/* filter
 *
 * FIR filter in assembly language
 *
 * the assembly language code goes in the file filter.S, in the libraries directory
 */

#include <filter.h>
#include "fir1.h"
#include "input2.h"

int output[NUM_SAMPS];

byte i = 26;
byte k = 0;

extern "C" {              
 void printRegs(void);
 int q15mpy(int, int);
}


void setup() {
  Serial.begin(9600);

 
  filter();



   for(int i = 26; i < NUM_SAMPS; i++){
     output[i]=0;
     for(int k = 0; k < 27; k++){     
      output[i] = output[i]+q15mpy(fir1[k],input[i-k]);
     }
    
      int inp = input[i];
      Serial.println(inp);
        Serial.write("@");
      Serial.write(0x04);
     long b = millis();
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
      
      
     
     if(inp<0){
     Serial.write(0x2d);
     inp = -inp;
     }
     else{
       Serial.write(0x2b);
     }
      int lowinp = inp & 0xff;
      int highinp = inp >> 8;
      Serial.write(highinp);
      Serial.write(lowinp);
      Serial.write("\r");
      delay(1000);
       
      Serial.write("@");
      Serial.write(0x05);
     long c = millis();
      long lowestc = c & 0xff;
      long sectolowc = c >> 8;
      sectolowc = sectolowc & 0xff;
      long sectohighc = c >> 16;
      sectohighc = sectohighc & 0xff;
      long highestc = c >> 24;
      Serial.write(highestc);
      Serial.write(sectohighc);
      Serial.write(sectolowc);
      Serial.write(lowestc);  
       
      int outp = output[i]; 
       if(outp<0){
     Serial.write(0x2d);
     outp = -outp;
     }
     else{
       Serial.write(0x2b);
     }
       int lowoutp = outp & 0xff;
      int highoutp = outp >> 8;
      Serial.write(highoutp);
      Serial.write(lowoutp);
       Serial.write("\r");
       delay(1000);
     
     }
     

}

void loop() {
   
}




extern "C" {
 int q15mpy(int x, int y) {
  return (((long int) x * (long int) y) >> 15);
 }
}
