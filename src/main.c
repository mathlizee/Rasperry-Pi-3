/*
 *  Author: Mathieu Lizee (mathieulizee1@gmail.com)
 *
 *  Main function.
 *  Called after memory and registers initialization.
 *
 */

#include "devices/act_led.h"
#include "system/system_timer.h"

void main()
{
  act_led_set_state(1);

  unsigned int start = system_timer_get_time();
  while (system_timer_get_time() - start <= 2000000);

  if (act_led_get_state())
  {
    act_led_set_state(0);
  }
  else
  {
    act_led_set_state(1);
  }

  // Infinite loop
  while (1);
}
