#include "motors.h"
#include "crt.h"
#include "sensors.h"


// int motor_slowspeed = 96;
// int motor_halfspeed = 127;
// int motor_fullspeed = 255;


void angry_eyes(){
    tft.fillScreen(BLACK);
    tft.setTextSize(3);
    tft.setCursor(0, 0);
    tft.setTextColor(RED);
    //tft.println(" ");
    tft.println(" =====");
    tft.println("|     |");
    tft.println("(@) (@)");
    tft.println("|_____|");
    tft.println("  |||  ");
   // crt_simple_message_line("  -   -");
}

String neutral_eyes_open = "  o    o";
String neutral_eyes_closed = "  -    -";

void nuetral_eyes(){
    tft.fillScreen(BLACK);
    tft.setTextSize(2);
    tft.setCursor(0, 0);
    tft.setTextColor(GREEN);
    tft.println(" ");
    tft.println("==========");
    tft.println(neutral_eyes_open);
    tft.println("==========");
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
  behavior_shake(40,16,motor_fullspeed);//
}

void machine_gun_shake(){
  behavior_shake(40,20,motor_fullspeed);//machine gun
}

void washing_machine_shake(){
  behavior_shake(20,40,motor_fullspeed);//washing machine
}


void backup_as_needed(){
  delay(2);
  int d = forward_distance();
  if(d>500){
    while ((d > 500))
    {
        /* near */
        backward(motor_fullspeed);
        delay(1);
        stop();
        d = forward_distance();
    }
    stop();
    angry_eyes();
    machine_gun_shake();
    delay(3000);
    nuetral_eyes();
  }

}

void check_for_near(int how_many_times){
  for (int i = 0; i < how_many_times; i++)
  {
    backup_as_needed();
  }
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
  crt_message_line(neutral_eyes_open);
  check_for_near(500);
  //delay(1000);
  crt_simple_message_line(neutral_eyes_closed);
  check_for_near(5);
  //delay(10);
  crt_message_line(neutral_eyes_open);
  check_for_near(250);
  //delay(500);
  crt_simple_message_line(neutral_eyes_closed);
  check_for_near(5);
  //delay(10);
  crt_message_line(neutral_eyes_open);
  check_for_near(500);
  //delay(1000);
}

void crt_greeting(){
  tft.fillScreen(BLACK);
  tft.setCursor(10, 0);
  tft.setTextSize(2);
  tft.setTextColor(GREEN);

  tft.println("greetings");
  tft.println("  human");
  tft.println("");
  tft.println("  I AM");
  tft.println("");
  tft.println(" DREADBOT");
}

void blinking(int how_many_times){
  for (int i = 0; i < how_many_times; i++)
  {
    check_for_near(1);
    blink();
  }  
}

void look_around(){
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

void steppin_out(){
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

void say_something(String something){
    crt_expression_line(something);
}


