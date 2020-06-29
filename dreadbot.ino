/*******************************************************************************

      DREADBOT

 *******************************************************************************/

#include "motors.h"
#include "crt.h"

// int motor_slowspeed = 96;
// int motor_halfspeed = 127;
// int motor_fullspeed = 255;

void setup() {

  crt_setup() ;
  behavior_shake(40,10,motor_fullspeed);//hum
  behavior_shake(40,5,motor_fullspeed);//hum
  crt_greeting();
  behavior_shake(40,12,motor_fullspeed);//
  behavior_shake(40,14,motor_fullspeed);//
  behavior_shake(40,16,motor_fullspeed);//
  //behavior_shake(50,20,motor_fullspeed);//machine gun
  //behavior_shake(25,40,motor_fullspeed);//washing machine
  blink();
  walk_forward(1);
  blink();
  walk_forward(2);
  blink();
  walk_backward(3);
  blink();
  spin_right(12);
  blink();
  blink();
  blink();
  spin_left(12);
  blink();
  blink();
  blink();
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

void spin_right(int how_many){
  for (size_t i = 0; i < how_many; i++)
  {
    right(motor_fullspeed);
    delay(60);
    stop();
  }
}

void spin_left(int how_many){
  for (size_t i = 0; i < how_many; i++)
  {
    left(motor_fullspeed);
    delay(60);
    stop();
  }
}

void walk_forward(int how_many_steps){
  for (int i = 0; i < how_many_steps; i++)
  {
    step_forward_right();
    delay(250);
    step_forward_left();
    delay(250);
  }
}

void walk_backward(int how_many_steps){
  for (int i = 0; i < how_many_steps; i++){
    step_backward_right();
    delay(250);
    step_backward_left();
    delay(250);
  }
}

void check_right(){
    crt_message_line("right");
    right(motor_fullspeed);
    delay(50);
    stop();
    delay(100);
}

void check_left(){
    crt_message_line("left");
    left(motor_fullspeed);
    delay(50);
    stop();
    delay(100);
    crt_message_line("   . .");
    delay(500);
    crt_message_line("     . .");
    delay(500);
    crt_message_line("   . .");
    delay(500);
    right(motor_fullspeed);
    delay(50);
    stop();
    crt_message_line(" . .");
    delay(100);
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
