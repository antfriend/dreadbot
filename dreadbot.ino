/*******************************************************************************

      DREADBOT

 *******************************************************************************/

#include "motors.h"
#include "crt.h"

void setup() {
  crt_setup() ;
  crt_greeting();
  step_forward_right();
  step_forward_left();
}

void loop() {
 //testloop();

}
