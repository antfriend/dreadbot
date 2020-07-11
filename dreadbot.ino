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
  tft.setCursor(2, 79);
  tft.println("DREDBOT");
  buzz_shake();
  delay(500);
  //shift name
  tft.setCursor(1, 81);
  tft.println("DREDBOT");
  delay(2000);
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
    the_message = " WHY?!?";
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
      matrix_face();
      break;
  default:
    crt_wait();
    random_delay();
    break;
  }
}

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
  for (int i = 0; i < 3; i++)
  {
    the_matrix_has_you();
  }
}
