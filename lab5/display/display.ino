/*Qian Wu
 * Lab section A
 * q.wu@wustl.edu
 * CSE 132 lab5
 * display.ino
 * display numbers and characters
 * */
    
    #include <Arduino.h>
    #include <Wire.h>
    #include <ST7036.h>
    #include "font.h"
    
    ST7036 lcd = ST7036 ( 2, 16, 0x7c );
    int array[5][7];
    int c = 23;
    void setup ()
    {
      //Serial.begin(9600);
      lcd.init ();
      lcd.setContrast(0);
      // insert code here as needed
      for(int i = 0; i< 12; i++){
        pinMode(i, OUTPUT);  
      }
      
    
    
    
    pinMode(12,INPUT_PULLUP); 
    pinMode(13,INPUT_PULLUP);
    pinMode(15,INPUT_PULLUP);
    pinMode(16,INPUT_PULLUP);
    
    
    
    

  
    }
    
    void loop ()
    {
      lcd.clear ();
      // insert code here as needed
       // "#" 
      for(int i = 0; i < 5; i++){
      array[i][0] = (font_5x7[c][i] & 128)>0;
      array[i][1] = (font_5x7[c][i] & 64)>0;
      array[i][2] = (font_5x7[c][i] & 32)>0;
      array[i][3] = (font_5x7[c][i] & 16)>0;
      array[i][4] = (font_5x7[c][i] & 8)>0;
      array[i][5] = (font_5x7[c][i] & 4)>0;
      array[i][6] = (font_5x7[c][i] & 2)>0; 
    }
      
    
      for(int i = 0; i < 5; i++){
        digitalWrite(i+7,HIGH);
        //Serial.print("i+7 = ");
        //Serial.print(i+7);
        for(int k = 0; k < 5; k ++ ){
          if (k != i){
            digitalWrite(k+7, LOW);
          }
        }
        for(int j = 0; j < 7; j++ ){
          if(array[i][j]==1){
          digitalWrite(j, LOW);
          }
          else{
            digitalWrite(j, HIGH);
          }
        }
        
        
      }
      
      if(digitalRead(12)==0){
        c  = c - 1;  
        delay(300);
      }
      else{
         if(digitalRead(15)==0) {
           c = c + 1;
           delay(300);
         }
         else{
             if(digitalRead(13)==0){
               c = c + 10;
               delay(300);
             }
             else{
              if (digitalRead(16)==0){
                c =  c - 10;
                delay(300);
              } 
             }
         }
      }
      
      
      
    }
