/*
 *  Author: Mathieu Lizee (mathieulizee1@gmail.com)
 *
 *  Header for the framebuffer.
 *  The framebuffer is a bitmap that is displayed on the screen.
 *
 */

// Method to initialize the framebuffer (get the framebuffer's pointer)
extern unsigned int* framebuffer_init(  unsigned int physical_width,
                                        unsigned int physical_height,
                                        unsigned int virtual_width,
                                        unsigned int virtual_height,
                                        unsigned int bit_depth);
