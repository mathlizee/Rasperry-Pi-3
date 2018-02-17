/*
 *  Author: Mathieu Lizee (mathieulizee1@gmail.com)
 *
 *  Header for the system timer.
 *  The sytem timer helps for time functionalities (waiting, timing, etc).
 *
 */

#include "system_timer.h"

/**
 * Get the current time
 * Returns the counter value of the system timer
 */
unsigned int system_timer_get_time()
{
  // Return the current time
  return *SYSTEM_TIMER_COUNTER_ADDR;
}
