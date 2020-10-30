#include <Encoder.h>

 
Encoder myEnc(2, 3);
 
void setup() {
  Serial.begin(9600);
  Serial.println("Basic Encoder Test:");
}
 
long oldPosition  = -999;
long oldtime_data = micros();
void loop() {
long newtime_data = micros();
  
 long newPosition = myEnc.read();
 newPosition = newPosition *360/1496;
// newPosition  = newPosition % 360;  

  if (newPosition  > 180) {
  newPosition = newPosition-360;
  }
  
 else if (newPosition  <= -180) {
  newPosition = 360 + newPosition;
  } 
  if(oldPosition != newPosition ){
   Serial.println(oldPosition);
   Serial.println(oldtime_data);
   long diff_Pos = newPosition - oldPosition;
   unsigned long diff_time = (newtime_data - oldtime_data);
   long  angular_velocity = 1000000 * diff_Pos / diff_time  ;
   oldPosition = newPosition;
   oldtime_data = newtime_data;
   long distance = diff_Pos * 56 * 3.14 *10 /360; //単位[cm]
   
    Serial.println("////////////////////////////////////");
    Serial.println(diff_Pos);
    Serial.println(diff_time);
    Serial.println(distance);
    Serial.println(angular_velocity);
    Serial.println(newPosition);
    Serial.println(newtime_data);
    }
delay(20);
    
}
