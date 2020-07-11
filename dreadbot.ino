#include "behaviors.h"

/*******************************************************************************

      DREADBOT

 *******************************************************************************/

void setup() {

  crt_setup() ;
  sensors_initialize();
  crt_greeting();
  hum_shake();
  buzz_shake();

  // delay(500);
  // tft.fillScreen(BLACK);
  // tft.println("whirr");
  // whirr_shake();
  // delay(500);
  // tft.println("grumble");
  // grumble_shake();
  // delay(500);
  // crt_message_line("machine   gun");
  // machine_gun_shake();
  // delay(500);
  // crt_message_line("washing   machine");
  // washing_machine_shake();
  // delay(500);

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
    the_message = "thats you";
    break;
  case 2:
    the_message = "   ~~~";
    break;
  case 3:
    the_message = "   WHY?!?";
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
    case 4:
      look_around();
      //front_to_color();
      break;
    case 5:
      distance_report();
      break;
    case 6:
      sequence1();
      break;
    case 7:
      look_around();
      break;
  default:
    crt_wait();
    random_delay();
    break;
  }
}
