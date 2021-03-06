 #include "CytronMotorDriver.h"

//https://docs.google.com/document/d/1EiQAE_9VpDDm4rjZrySAoGjQldJnTk6rJIsUkqCT37w/view
CytronMD motor1(PWM_DIR, 5, 4);  //Signed Magnitude PWM 1 = Pin 5, DIR 1 = Pin 4.
CytronMD motor2(PWM_DIR, 6, 7); //Signed Magnitude PWM 2 = Pin 6, DIR 2 = Pin 7.
int motor_slowspeed = 96;
int motor_halfspeed = 127;
int motor_fullspeed = 255;


void forward(int howfast){
  motor1.setSpeed(howfast);
  motor2.setSpeed(howfast);
}

void backward(int howfast){
  motor1.setSpeed(-howfast);
  motor2.setSpeed(-howfast);
}

void right(int howfast){
  motor1.setSpeed(howfast);
  motor2.setSpeed(-howfast);
}

void left(int howfast){
  motor1.setSpeed(-howfast);
  motor2.setSpeed(howfast);
}

void stop(){
  motor1.setSpeed(0);
  motor2.setSpeed(0);
}

void sequence1(int howfast){
  forward(howfast);
  delay(1000);
  stop();
  delay(300);
  backward(howfast);
  delay(1000);
  stop();
  delay(1000);

  right(howfast);
  delay(1000);
  left(howfast);
  delay(1000);
  
  stop();
  delay(1000);
}

void step_forward_right(){
  motor1.setSpeed(motor_fullspeed);
  delay(60);
  stop();
  delay(10);
}

void step_forward_left(){
  motor2.setSpeed(motor_fullspeed);
  delay(60);
  stop();  
  delay(10);
}

void step_backward_right(){
  motor1.setSpeed(-motor_fullspeed);
  delay(60);
  stop();
  delay(10);
}

void step_backward_left(){
  motor2.setSpeed(-motor_fullspeed);
  delay(60);
  stop();  
  delay(10);
}

void testloop(){
  int howfast = 0;
  stop();
  delay(3000);
  howfast = 127;
  sequence1(howfast);
  howfast = 127;
  sequence1(howfast);
}
