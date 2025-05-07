#ifndef FLEX_SYSTEM_H
#define FLEX_SYSTEM_H

#include <stdint.h>

// System Initialization Functions
void system_init(void);
void system_start(void);
void system_halt(void);
void system_init_hardware(void);

// Keyboard Driver Functions
void keyboard_init(void);
int keyboard_read(void);
void keyboard_interrupt_handler(void);

// Mouse Driver Functions
void mouse_init(void);
void mouse_read(int *x, int *y, int *button_status);
void mouse_interrupt_handler(void);

// Audio Driver Functions
void audio_init(void);
void audio_play_sound(uint16_t frequency, uint32_t duration);
void audio_interrupt_handler(void);

// Utility Functions
void system_print(const char *msg);
void delay(uint32_t milliseconds);

#endif // FLEX_SYSTEM_H
