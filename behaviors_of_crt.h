#include "crt.h"

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
    tft.println(" ~~~~~");
    delay(1000);
    tft.fillScreen(BLACK);
    tft.setTextSize(10);
    tft.setCursor(0, atX);
    tft.setTextColor(GREEN);
    tft.println(":P");
    delay(1000);
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

