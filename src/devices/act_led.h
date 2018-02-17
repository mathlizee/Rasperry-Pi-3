/*
 *  Author: Mathieu Lizee (mathieulizee1@gmail.com)
 *
 *  Header for the ACT_LED on the RaspberryPi 3.
 *
 */

// Header for the ACT LED message
#define ACT_LED_MESSAGE_SIZE    (8 * 4)
#define ACT_LED_REQUEST_CODE    (0)

// Tag header
#define ACT_LED_TAG_GET_STATE   (0x00030041)
#define ACT_LED_TAG_SET_STATE   (0x00038041)
#define ACT_LED_VALUE_BUF_SIZE  (8)
#define ACT_LED_RESPONSE_SIZE   (0)

// Tag data
#define ACT_LED_PIN_NUMBER      (130)
#define ACT_LED_STATE_ON        (1)
#define ACT_LED_STATE_OFF       (0)
#define ACT_LED_END_TAG         (0)

// Method to change the state of the ACT LED
extern void act_led_set_state(unsigned char state);

// Method to get the state of the ACT LED
extern unsigned char act_led_get_state();
