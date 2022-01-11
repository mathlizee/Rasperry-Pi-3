/*
 *  Author: Mathieu Lizee
 *
 *  Start up routine.
 *  Initialize the stack pointer and calls main().
 *
 */

.section .init
.global _start

_start:
  mov sp, #0x8000  @; Init stack pointer
  bl main @; Should not return from main

$loop:
  b $loop @; Infinite loop for safety
