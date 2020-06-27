/*******************************************************************************

      DREADBOT

 *******************************************************************************/

#include "motors.h"
#include "crt.h"

//int motor_halfspeed = 127;
//int motor_fullspeed = 255;

void setup() {
  behavior_shake(2,20);
  crt_setup() ;
  crt_greeting();
  //step_forward_right();
  //step_forward_left();
  behavior_shake(4,50);
  delay(500);
  behavior_shake(2,100);
}

void loop() {
  crt_wait();
  crt_greeting();
  behavior_shake(2,20);

}

void behavior_shake(int shaketimes, int turn_duration){
  for(int i = 1; i <= shaketimes; i++ ){
    right(motor_fullspeed);
    delay(turn_duration);
    stop();
    left(motor_fullspeed);
    delay(turn_duration);  
    stop();
  }
}
