/*Qian Wu
 * Lab section A
 * q.wu@wustl.edu
 * CSE 132 lab3
 *filter.ino
 * filter the data
 * */

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


  //The C code is suppressed below
   for(int i = 26; i < NUM_SAMPS; i++){
     output[i]=0;
     for(int k = 0; k < 27; k++){
       //Serial.println(q15mpy(fir1[k],input[i-k]));
       output[i] = output[i]+q15mpy(fir1[k],input[i-k]);
     }
     }
     
 for(int i = 26; i < NUM_SAMPS; i++){
  Serial.println(output[i]);
 }

}

void loop() {
  
}




extern "C" {
 int q15mpy(int x, int y) {
  return (((long int) x * (long int) y) >> 15);
 }
}
