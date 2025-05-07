#ifndef FLEX_SYSTEM_H
#define FLEX_SYSTEM_H

// System Initialization
void system_halt(void);

// Hardware Interfaces
void system_init_hardware(void);

// Keyboard Driver
void keyboard_init(void);
int keyboard_read(void);

// Mouse Driver
void mouse_init(void);
void mouse_read(int *x, int *y, int *button_status);

// Audio Driver
void audio_init(void);
void audio_play_sound(uint16_t frequency, uint32_t duration);

#endif // FLEX_SYSTEM_H
