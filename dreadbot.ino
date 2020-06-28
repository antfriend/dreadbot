/*******************************************************************************

      DREADBOT

 *******************************************************************************/

#include "motors.h"
#include "crt.h"

// int motor_slowspeed = 96;
// int motor_halfspeed = 127;
// int motor_fullspeed = 255;

void setup() {
  behavior_shake(8,20,motor_halfspeed);
  crt_setup() ;
  crt_greeting();
  //step_forward_right();

}

void loop() {
  random_behavior();
  random_delay();
}


/*
behaviors
*/
void random_behavior(){
  long count_of_things = 3;
  long random_thing = random(0,count_of_things);
  switch (random_thing)
  {
  case 1:
    sequence1();
    break;
    case 2:
    check_left();
    break;
    case 3:
    behavior_shake(4,50,motor_halfspeed);;
    break;
  default:
    crt_wait();
    random_delay();
    break;
  }
}

void sequence1(){
  crt_message_line("seq 1");
  check_right();
  crt_wait();
  check_right();
  check_right();
  crt_wait();
}

void random_delay(){
  delay(random(1000,10000));
}

void check_right(){
    right(motor_halfspeed);
    delay(50);
    stop();
    delay(100);
}

void check_left(){
    crt_message_line("left");
    left(motor_slowspeed);
    delay(1000);
    stop();
    delay(100);
    crt_message_line("   . .");
    delay(500);
    crt_message_line("     . .");
    delay(500);
    crt_message_line("   . .");
    delay(500);
    right(motor_slowspeed);
    delay(1000);
    stop();
    crt_message_line(" . .");
    delay(100);
    // left(90);
    // delay(500);
    // stop();
}

void behavior_shake(int shaketimes, int turn_duration, int turn_speed){
  for(int i = 1; i <= shaketimes; i++ ){
    right(turn_speed);
    delay(turn_duration);
    stop();
    left(turn_speed);
    delay(turn_duration);  
    stop();
  }
}
