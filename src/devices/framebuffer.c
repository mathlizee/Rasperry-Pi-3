/*
 *  Author: Mathieu Lizee
 *
 *  Header for the framebuffer.
 *  The framebuffer is a bitmap that is displayed on the screen.
 *
 */

#include "framebuffer.h"

#include "../system/mailbox.h"

/**
 *  Initialize the framebuffer and gets the framebuffer pointer
 *
 *  physical_width: Physical width of the screen
 *  physical_height: Physical height of the screen
 *  virtual_width: Virtual width, will be scaled to the physical width
 *  virtual_height: Virtual height, will be scaled to the physical height
 *  bit_depth: Number of bits per color
 */
unsigned int* framebuffer_init( unsigned int physical_width,
                                unsigned int physical_height,
                                unsigned int virtual_width,
                                unsigned int virtual_height,
                                unsigned int bit_depth)
{
  // Property Info buffer
  //volatile unsigned int __attribute__((aligned(16))) framebuffer_request[10];

  /*// Since the request can fail, it must be send multiples times until it succeeds
  while (1)
  {
    // Fill the mailbox with the framebuffer request
    framebuffer_request[0] = physical_width;
    framebuffer_request[1] = physical_height;
    framebuffer_request[2] = virtual_width;
    framebuffer_request[3] = virtual_height;
    framebuffer_request[4] = 0; // Pitch, will be filled by the GPU
    framebuffer_request[5] = bit_depth;
    framebuffer_request[6] = 0; // X offset on the screen
    framebuffer_request[7] = 0; // Y offset on the screen
    framebuffer_request[8] = 0; // Framebuffer's pointer, will be filled by the GPU
    framebuffer_request[9] = 0; // Framebuffer's size, will be filled by the GPU

    // Write the message's address in the mailbox
    // Since L2 cache is enabled, MAILBOX_VC_MMU_OFFSET must be added to the address
    mailbox_write(((unsigned long) &framebuffer_request) + MAILBOX_VC_MMU_OFFSET, MAILBOX_CH_FRAMEBUFFER);

    // Read the response from the GPU
    // If it's 0, then the request has failed; succeeded otherwise
    if (mailbox_read(MAILBOX_CH_FRAMEBUFFER) == 0 && framebuffer_request[8] != 0) break;
  }

  act_led_turn_on();

  return (unsigned int*)(framebuffer_request[8] - MAILBOX_VC_MMU_OFFSET);*/
  return 0;
}
