#include "behaviors.h"

/*******************************************************************************

      DREADBOT

 *******************************************************************************/

void setup() {
  crt_setup() ;
  sensors_initialize();
  crt_greeting();
  hum_shake();
  //shift name
  tft.setCursor(1, 82);
  tft.setTextColor(GREEN); 
  tft.println("DREDBOT");
  buzz_shake();
  //shift name
  tft.setCursor(2, 84);
  tft.setTextColor(RED); 
  tft.println("DREDBOT");
  washing_machine_shake();
  step_forward_left();
  delay(2000);
}


String random_phrase(){
  String the_message;
  int rando = random(0,7);
  switch (rando)
  {
  case 0:
    the_message = "I am happy";
    break;
  case 1:
    the_message = "hey you";
    break;
  case 2:
    the_message = "   ~~~";
    break;
  case 3:
    the_message = " ~~~";
    break;
  case 4:
    the_message = "    ...";
    break;
  case 5:
    the_message = "    hi";
    break;
  case 6:
    the_message = "\n  what?";
    break;
  default:
    the_message = "  default";
    break;
  }
  return the_message;
}

void loop() {
  nuetral_eyes();
  say_something(random_phrase());
  blinking(1);
  nuetral_eyes();
  random_behavior();
  random_delay();
}

void testFireOne(){
  say_something("firing in 3");
  delay(1000);
  say_something("firing in 2");
  delay(1000);
  say_something("firing in 1");
  delay(1000);
  say_something("FIRE!!!!!!!");
  delay(1000);
  FireOne();
  delay(3000);
}



/*
behave!
*/
void random_behavior(){
  long count_of_things = 8;
  long random_thing = random(0,count_of_things);
  switch (random_thing)
  {
    case 1:
      steppin_out();
      break;
    case 2:
      check_left();
      break;
    case 3:
      grumble_shake();
      break;
    // case 4:
    //   front_to_color();
    //   break;
    // case 5:
    //   distance_report();
    //   break;
    // case 6:
    //   sequence1();
    //   break;
    case 7:
      matrix_face();
      break;
  default:
    //crt_wait();
    look_around();
    random_delay();
    break;
  }
}
