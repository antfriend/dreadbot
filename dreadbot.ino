
#include "behaviors.h"
#include <TimerOne.h>                           // Header file for TimerOne library
 
/*******************************************************************************

      DREADBOT

 *******************************************************************************/

#define TIMER_US 4000000                      // 1000mS set timer duration in microseconds 
#define TICK_COUNTS 8                         //worth of timer ticks
volatile long tick_count = TICK_COUNTS;         // Counter for 2S
volatile bool in_long_isr = false;              // True if in long interrupt

void setup() {

  crt_setup() ;
  sensors_initialize();

  Timer1.initialize(TIMER_US);                  // Initialise timer 1
  Timer1.attachInterrupt( timerIsr );           // attach the ISR routine here

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


// --------------------------
// timerIsr() 100 milli second interrupt ISR()
// Called every time the hardware timer 1 times out.
// --------------------------
void timerIsr()
{
    //digitalWrite( LED0, digitalRead( LED0 ) ^ 1 );   // Toggle LED 0
    hum_shake();

    if (!(--tick_count))                             // Count to 2S
    {
      tick_count = TICK_COUNTS;                      // Reload
      tick_2s_isr();                                 // Call the 2S routine
    }
}


// --------------------------
// tick_2s_isr() 2 second routine
// Called every time the count gets to 2S
// --------------------------
void tick_2s_isr()
{
    if (in_long_isr)                                // Prevent reentering this code
    {
      return;
    }
    
    in_long_isr = true;                             // Indicates we are in the long isr
    
    volatile long i;

    interrupts();                                   // Enable interrupts
    //digitalWrite( LED1, digitalRead( LED1 ) ^ 1 );  // Toggle LED 1
    buzz_shake();
    // for (i = 0; i < 400000; i++)                   // Delay because delay() will not work here
    // {
    // }
   
    noInterrupts();                                 // Disable interrupts
    in_long_isr = false;                            // Indicates exit of the long isr
}


String random_phrase(){
  String the_message;
  int rando = random(0,7);
  switch (rando)
  {
  case 0:
    the_message = "human\r\n detected";
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
  i_am_happy();
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
      steppin_out_left();
      break;
    case 2:
      steppin_out_right();
      break;
    case 3:
      grumble_shake();
      break;
    case 4:
      i_am_happy();
      break;
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
