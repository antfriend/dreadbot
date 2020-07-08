
#include "motors.h"
#include "crt.h"
#include "sensors.h"

/*******************************************************************************

      DREADBOT

 *******************************************************************************/

// int motor_slowspeed = 96;
// int motor_halfspeed = 127;
// int motor_fullspeed = 255;

String interpret_d(int d){
  String d_result = String(d);
  if(d <= 50){
    d_result = "far";
  }
  if(d > 500){
    d_result = "near";
  }
  return d_result;
}

String interpret_color(int d){
  String d_result = String(d);
  if(d <= 50){
    d_result = "far";
  }
  if(d > 500){
    d_result = "near";
  }
  return d_result;
}

void front_to_color(){

  for (int i = 0; i < 100; i++)
  {
    int d = forward_distance();
    int rad = map(d,50,500,1,64);

    if(d <= 50){
      //"far"
      tft.fillCircle(64, 64, 64, BLUE);
      continue;
    }
    if(d > 500){
      //"near"
      check_for_near(1);
      tft.drawCircle(64, 64, rad, RED);
      continue;
    }
    //draw a green circle
    tft.drawCircle(64, 64, rad, GREEN);
    tft.drawCircle(64, 64, rad+1, MAGENTA);
    tft.drawCircle(64, 64, rad-1, YELLOW);
    check_for_near(8);
    //delay(16);//60 frames second
  }
}

void blink(){
  crt_message_line("  o   o");
  check_for_near(500);
  //delay(1000);
  crt_simple_message_line("  -   -");
  check_for_near(5);
  //delay(10);
  crt_message_line("  o   o");
  check_for_near(250);
  //delay(500);
  crt_simple_message_line("  -   -");
  check_for_near(5);
  //delay(10);
  crt_message_line("  o   o");
  check_for_near(500);
  //delay(1000);
}

void crt_greeting(){
  //tft.fillRect(0, 0, 128, 128, BLACK);
  tft.setCursor(10, 0);
  tft.fillScreen(BLACK);
  tft.setTextSize(2);
  tft.setTextColor(GREEN);

  tft.println(" ");
  tft.println("==========");
  tft.println("  hello! ");
  tft.println("==========");
  tft.println(" ");
  tft.println(" \\(^o^)/");
  delay(2000);
  crt_clear_bottom_half();

  look_middle();
  delay(1000);

  look_right();
  delay(1000);

  look_middle();
  delay(1000);

  look_left();
  delay(1000);
  blink();  
}

void backup_as_needed(){
  delay(2);
  int d = forward_distance();
  while ((d > 500))
  {
    /* near */
    backward(motor_fullspeed);
    delay(1);
    stop();
    d = forward_distance();
  }
  stop();
}

void check_for_near(int how_many_times){
  for (int i = 0; i < how_many_times; i++)
  {
    backup_as_needed();
  }
}

void distance_report(){
    for (size_t i = 0; i < 100; i++)
    {
      String left_d = interpret_d(left_distance());
      String front_d = interpret_d(forward_distance());
      String right_d = interpret_d(right_distance());
      String message4me = String(PIR());
      message4me = right_d + " " + front_d + " " + left_d;
      crt_message_line(message4me);
      check_for_near(10);
      //delay(10);
    }
}

void setup() {

  crt_setup() ;
  sensors_initialize();
  behavior_shake(40,10,motor_fullspeed);//hum
  behavior_shake(80,5,motor_fullspeed);//hum
  //front_to_color();
  //distance_report();

  crt_greeting();
  
  behavior_shake(40,12,motor_fullspeed);//
  behavior_shake(40,14,motor_fullspeed);//
  behavior_shake(40,16,motor_fullspeed);//

  //behavior_shake(50,20,motor_fullspeed);//machine gun
  //behavior_shake(25,40,motor_fullspeed);//washing machine
  blinking(1);
  walk_forward(1);
  blinking(1);
  walk_forward(2);
  blinking(1);
  walk_backward(3);
  blinking(1);
  spin_right(12);
  blinking(3);
  spin_left(12);
  blinking(3);
}

void blinking(int how_many_times){
  for (int i = 0; i < how_many_times; i++)
  {
    check_for_near(1);
    blink();
  }
  
}
void loop() {
  random_behavior();
  random_delay();
}


/*
behaviors
*/
void random_behavior(){
  long count_of_things = 6;
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
    case 4:
      front_to_color();
      break;
    case 5:
      distance_report();
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
  int random_times = random(100,800);
  check_for_near(random_times);
  //delay(random(100,10000));
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
