/*
 *  Author: Mathieu Lizee
 *
 *  Header for the system timer.
 *  The sytem timer helps for time functionalities (waiting, timing, etc).
 *
 */

 // System timer addresses
 #define SYSTEM_TIMER_BASE_ADDR     (0x3f003000)

 #define SYSTEM_TIMER_COUNTER_ADDR  ((volatile unsigned int*) (SYSTEM_TIMER_BASE_ADDR + 0x4))

 // Method to get the current time counter value
 extern unsigned int system_timer_get_time();
