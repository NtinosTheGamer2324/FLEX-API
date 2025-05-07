#ifndef FLEX_SYSTEM_H
#define FLEX_SYSTEM_H

// System initialization and main functions
void system_init(void);
void system_start(void);
void system_halt(void);

// Hardware initialization and drivers
void system_init_hardware(void);

// Keyboard, Mouse, and Audio initialization
void keyboard_init(void);
void mouse_init(void);
void audio_init(void);

// Read inputs
int keyboard_read(void);
void mouse_read(int* x, int* y, int* button_status);

// Audio functions (simplified)
void audio_play_sound(const char* sound_file);

// Print message to the screen (system-dependent)
void system_print(const char* message);

#endif // FLEX_SYSTEM_H
