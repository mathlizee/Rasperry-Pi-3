/*
 *  Author: Mathieu Lizee (mathieulizee1@gmail.com)
 *
 *  Source for the mailbox.
 *  The mailbox helps with communication between the CPU and the GPU.
 *
 */

 #include "mailbox.h"

 // Mailbox buffer (must be 16-byte aligned)
volatile unsigned int __attribute__((aligned(16))) mailbox[8];

/**
 *  Write a message in the mailbox
 *
 *  channel: Channel of the mailbox to use
 */
void mailbox_write(unsigned long data, unsigned char channel)
{
  // Wait until the mailbox is empty
  while (*MAILBOX_STATUS_ADDR & MAILBOX_STATUS_FULL);

  // Write the address of the message in the mailbox
  // The last four bits of the message need to be replaced by the channel
  *MAILBOX_WRITE_ADDR = (((unsigned int) data & ~0xF) | (channel & 0xF));
}

/**
 *  Read a message (or a response) from the mailbox
 *  Returns the response that was in the mailbox
 *
 *  channel: Channel of the mailbox where the response should be
 */
unsigned int mailbox_read(unsigned char channel)
{
  unsigned int response;

  // Loop until a response has been returned
  while (1)
  {
    // Wait until the mailbox is full
    while (*MAILBOX_STATUS_ADDR & MAILBOX_STATUS_EMPTY);

    // Read the response
    response = *MAILBOX_READ_ADDR;

    // Verify that the response came from the right channel
    if (((unsigned char) (response & 0xF)) == channel)
    {
      // Return the upper 28 bits
      return response >> 4;
    }
  }
}
