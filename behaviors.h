

#include "sensors.h"
#include "behaviors_of_treads.h"
#include "behaviors_of_crt.h"

// int motor_slowspeed = 96;
// int motor_halfspeed = 127;
// int motor_fullspeed = 255;

void i_am_happy(){
  nuetral_eyes();
  say_something("i am happy");
  
  delay(3000);
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


void backup_as_needed(){
  delay(2);
  int d = forward_distance();
  if(d>500){
    while ((d > 400))
    {
        /* near */
        backward(motor_fullspeed);
        delay(1);
        stop();
        d = forward_distance();
    }
    stop();
    angry_eyes();
    grumble_shake();
    // machine_gun_shake();
    //walk_forward(1);
    FireOne();
    washing_machine_shake();
    //machine_gun_shake();
    step_forward_left();
    //step_backward_right();
    delay(3000);
    calming_down();
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
    tft.setCursor(0, 0);
    tft.setTextColor(WHITE);
    tft.setTextSize(1);
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
  check_left();
  check_right();
  crt_wait();
}

void random_delay(){
  int random_times = random(100,800);
  check_for_near(random_times);
  //delay(random(100,10000));
}

void steppin_out_right(){
  blinking(1);
  walk_forward(1);
  blinking(1);
  check_right();
  walk_forward(2);
  blinking(1);
  walk_backward(3);
  //blinking(1);
  check_left();
  walk_backward(3);
  // spin_right(12);
  // blinking(3);
  // spin_left(12);
  // blinking(3);
}

void steppin_out_left(){
  blinking(1);
  walk_forward(1);
  blinking(1);
  check_left();
  walk_forward(2);
  blinking(1);
  walk_backward(3);
  check_right();
  walk_backward(3);
}
