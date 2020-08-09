
#include "crt.h"
#include "sensors.h"
#include "behaviors_of_treads.h"


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

void calming_down(){
    int atX = 30;
    tft.fillScreen(BLACK);
    tft.setTextSize(3);
    tft.setCursor(0, atX);
    tft.setTextColor(YELLOW);
    tft.println(" =   =");
    delay(3000);
    tft.fillScreen(BLACK);
    tft.setCursor(0, atX);
    tft.println(" O   O");
    tft.println("   o");
    delay(1000);
    tft.setCursor(0, atX);
    //tft.fillScreen(BLACK);
    tft.println(" =   =");
    //tft.println("   ~");
    delay(1);
    tft.fillScreen(BLACK);
    tft.setCursor(0, atX);
    tft.println(" O  O");
    tft.println("   ~");
    delay(1000);
    tft.fillScreen(BLACK);
    tft.setTextSize(10);
    tft.setCursor(0, atX);
    tft.setTextColor(GREEN);
    tft.println(":P");
    delay(1000);
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
    //machine_gun_shake();
    //machine_gun_shake();
    walk_forward(1);
    FireOne();
    washing_machine_shake();
    machine_gun_shake();
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

void crt_greeting(){
  tft.fillScreen(BLACK);
  tft.setCursor(10, 0);
  tft.setTextSize(2);
  tft.setTextColor(GREEN);

  tft.println("greetings");
  tft.println("   human");
  tft.println("");
  tft.println("   I AM");
  tft.println("");
  tft.setTextSize(3);
  tft.setTextColor(YELLOW); 
  tft.println("DREDBOT");
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
  check_right();
  check_right();
  crt_wait();
}

void random_delay(){
  int random_times = random(100,800);
  check_for_near(random_times);
  //delay(random(100,10000));
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

/* 
  Matrix face stuff 
*/

String rnd_O_char(){
  int randy = random(0,7);
  switch (randy)
  {
  case 0:
    return " ";
    break;
  case 1:
    return "o";
    break;
  case 2:
    return "=";
    break;
  case 3:
    return "@";
    break;
  case 4:
    return "|";
    break;
  
  default:
    return " ";
    break;
  }
}

int rando_column_length(){
  int io = random(0,1);
  if(io == 0){
    return 0;
  }
  io = random(1,8);
  return io;
}

void the_matrix_has_you(){
  
  int columnals = 10;
  int columns[columnals];
  int my_y = 0;
  int my_x = 0;

  for (int c = 0; c < columnals; c++)
  {
    columns[c] = rando_column_length();
  }

  my_y = 1;
  for (int the_Row = 0; the_Row < 128; the_Row=the_Row+16)
  {
    
    my_x = 0;
    for (int coluCount = 0; coluCount < columnals-2; coluCount++)
    {
      if (columns[coluCount] > 0)
      {
        tft.setCursor(my_x, the_Row);
        tft.print(rnd_O_char());
      }else{
        tft.setCursor(my_x, the_Row);
        tft.print(rnd_O_char());
      }
      my_x = my_x + 16;
      //my_y = my_y + 2;
      //tft.print(my_y);
      delay(20);
    }
    //my_y = my_y + 10;
    //tft.println(" it ");
    //tft.println(rnd_O_char());
    //delay(100);
  }
}

void matrix_face(){
  tft.fillScreen(BLACK);
  tft.setTextSize(2);
  tft.setTextColor(GREEN);
  for (int i = 0; i < 5; i++)
  {
    the_matrix_has_you();
  }
}

