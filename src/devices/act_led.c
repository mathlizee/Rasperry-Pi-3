/*
 *  Author: Mathieu Lizee
 *
 *  Source for the ACT_LED on the RaspberryPi 3.
 *
 */

#include "act_led.h"

#include "../system/mailbox.h"

/**
 *  Get the state of the ACT LED
 *  Returns the ACT LED state (0: off, other: on)
 */
unsigned char act_led_get_state()
{
  // State of the ACT LED
  unsigned char state;

  // Property Info buffer
  volatile unsigned int __attribute__((aligned(16))) property_info[8];

  // Fill the message infos
  property_info[0] = ACT_LED_MESSAGE_SIZE;
  property_info[1] = ACT_LED_REQUEST_CODE;
  property_info[2] = ACT_LED_TAG_GET_STATE;
  property_info[3] = ACT_LED_VALUE_BUF_SIZE;
  property_info[4] = ACT_LED_RESPONSE_SIZE;
  property_info[5] = ACT_LED_PIN_NUMBER;
  property_info[6] = (unsigned int) &state;
  property_info[7] = ACT_LED_END_TAG;

  // Send the message to the GPU by the mailbox
  mailbox_write((unsigned long) &property_info, MAILBOX_CH_PROPERTY);

  // Read the response from the GPU
  mailbox_read(MAILBOX_CH_PROPERTY);

  // Return the state of the ACT LED
  // For unknown reasons, the status returned by the GPU is reversed
  return !state;
}

/**
 *  Change the state of the ACT LED
 *
 *  state: the new state of the ACT LED (0: off, other: on)
 */
void act_led_set_state(unsigned char state)
{
  // Property Info buffer
  volatile unsigned int __attribute__((aligned(16))) property_info[8];

  // Fill the message infos
  property_info[0] = ACT_LED_MESSAGE_SIZE;
  property_info[1] = ACT_LED_REQUEST_CODE;
  property_info[2] = ACT_LED_TAG_SET_STATE;
  property_info[3] = ACT_LED_VALUE_BUF_SIZE;
  property_info[4] = ACT_LED_RESPONSE_SIZE;
  property_info[5] = ACT_LED_PIN_NUMBER;
  property_info[6] = state;
  property_info[7] = ACT_LED_END_TAG;

  // Send the message to the GPU by the mailbox
  mailbox_write((unsigned long) &property_info, MAILBOX_CH_PROPERTY);

  // Read the response from the GPU
  mailbox_read(MAILBOX_CH_PROPERTY);
}
