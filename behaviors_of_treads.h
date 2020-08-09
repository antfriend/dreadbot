#include "motors.h"

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


void hum_shake(){
    behavior_shake(80,5,motor_fullspeed);
}
void buzz_shake(){
  behavior_shake(40,10,motor_fullspeed);
}

void whirr_shake(){
  behavior_shake(40,14,motor_fullspeed);//
}

void grumble_shake(){
  behavior_shake(30,16,motor_fullspeed);//
}

void machine_gun_shake(){
  behavior_shake(8,20,motor_fullspeed);//machine gun
}

void washing_machine_shake(){
  behavior_shake(5,40,motor_fullspeed);//washing machine
  //step_backward_left();
  //step_backward_right();
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

void extreme_happy_spin(){
  spin_right(12);
  buzz_shake();
  spin_left(12);
}
