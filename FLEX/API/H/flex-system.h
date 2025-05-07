#ifndef FLEX_SYSTEM_H
#define FLEX_SYSTEM_H

// Initialization Functions
void system_init(void);
void system_start(void);
void system_halt(void);
void system_print(const char* msg);

// Hardware Functions
void system_init_hardware(void);

// Keyboard, Mouse, and Audio Drivers
void keyboard_init(void);
int keyboard_read(void);
void mouse_init(void);
void mouse_read(int* x, int* y, int* button_status);
void audio_init(void);
void audio_play_sound(const char* sound_file);

#endif // FLEX_SYSTEM_H
