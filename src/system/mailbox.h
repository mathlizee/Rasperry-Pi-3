/*
 *  Author: Mathieu Lizee
 *
 *  Header for the mailbox.
 *  The mailbox helps with communication between the CPU and the GPU.
 *
 */

// Mailbox address
#define MAILBOX_BASE          (0x3f00b880)
#define MAILBOX_VC_MMU_OFFSET (0xC0000000)

#define MAILBOX_READ_ADDR     ((volatile unsigned int*) (MAILBOX_BASE))
#define MAILBOX_STATUS_ADDR   ((volatile unsigned int*) (MAILBOX_BASE + 0x18))
#define MAILBOX_WRITE_ADDR    ((volatile unsigned int*) (MAILBOX_BASE + 0x20))

// Mailbox channels
#define MAILBOX_CH_PROPERTY   (8)

// Mailbox status
#define MAILBOX_STATUS_FULL   (0x80000000)
#define MAILBOX_STATUS_EMPTY  (0x40000000)

// Write in the mailbox
void mailbox_write(unsigned long data, unsigned char channel);

// Read from the mailbox
unsigned int mailbox_read(unsigned char channel);
