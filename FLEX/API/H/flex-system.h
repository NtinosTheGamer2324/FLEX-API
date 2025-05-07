#ifndef FLEX_SYSTEM_H
#define FLEX_SYSTEM_H

// Initialize core system components, including hardware drivers
void system_init(void);

// Initialize hardware drivers (keyboard, mouse, audio)
void system_init_hardware(void);

// Start the system, running the main kernel process
void system_start(void);

// Halt the system
void system_halt(void);

// Restart the system
void system_restart(void);

// Print system-level messages (debugging, logging)
void system_print(const char* message);

// Get the system uptime in ticks
unsigned long system_uptime(void);

// Keyboard input handling function (simplified)
int keyboard_read(void);

// Mouse input handling function (simplified)
void mouse_read(int* x, int* y, int* button_status);

// Audio driver initialization and control
void audio_init(void);
void audio_play_sound(const char* sound_file);

#endif // FLEX_SYSTEM_H
