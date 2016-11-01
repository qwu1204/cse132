  /*Qian Wu
 * Lab section A
 * q.wu@wustl.edu
 * CSE 132 lab2
 *temperature2.ino
 * generate filtered and unfiltered temperature data
 * */
        
            const int analogInPin = A0;  // Analog input pin
            const int filterSize = 10;
            double unfiltered[filterSize]; 
            int count = 0; 
            float total = 0;      
            int count2 = 0;
            double average;
            double timec;
            double deltatime = 1000;
            double lasttime = millis();
      void setup() {
          // put your setup code here, to run once:
          analogReference(INTERNAL);
          
          Serial.begin(9600);
          }
          
      void loop() {
           
          if (millis()-lasttime >=1000){
        lasttime = millis();
          
          
         float raw = (float)(analogRead(analogInPin));
          float  temp = (float)(analogRead(analogInPin))*100*1.1/1023 - 50;
          unfiltered[count2]=temp; //places temperature in array
          count2++; 
          if(count>=5){ 
            if(count2>=filterSize){
              count2 = 0; //Goes back to the first point in the array if array fills
            }
            for(int i = 0; i<filterSize;i++){
            total += unfiltered[i];    //Adds all terms in the array
            }
            average=total/(double)filterSize; //Computes average
            total=0;
          
          
            Serial.print(raw);
            Serial.print(" ");      
           Serial.print(millis());
           timec = millis();
           Serial.print(" ");
            Serial.print(average);
            Serial.print(" ");
            Serial.println(temp);
      
          
              }
            count++;
          
          }
          
      }
