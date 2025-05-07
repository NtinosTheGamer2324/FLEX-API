#include "flex-system.h"
#include <stdint.h>

// Keyboard Buffer and Mouse Position
volatile unsigned char keyboard_buffer[256];  // Buffer to store key events
int mouse_x = 0, mouse_y = 0, mouse_button_status = 0;  // Mouse state

volatile unsigned long uptime = 0;  // Simulated uptime for demonstration

void system_init(void) {
    system_init_hardware();
    system_print("FlexOS initialized.\n");
    keyboard_init();
    mouse_init();
    audio_init();
}

void system_start(void) {
    system_print("FlexOS starting...\n");

    while (1) {
        uptime++;
        int key = keyboard_read();
        if (key != -1) {
            system_print("Key pressed: ");
            char msg[2] = {(char)key, '\0'};
            system_print(msg);
        }

        int x, y, button;
        mouse_read(&x, &y, &button);
        system_print("Mouse position: ");
        char pos[50];
        sprintf(pos, "X:%d Y:%d Buttons: %d", x, y, button);
        system_print(pos);
    }
}

void system_halt(void) {
    system_print("System halting...\n");
    while (1);  // Halt system
}

void system_print(const char* msg) {
    // Simple print function (replace with actual system-specific output method)
    // Would typically use direct screen memory writes, framebuffer, etc.
    printf("%s", msg);
}

void system_init_hardware(void) {
    system_print("Initializing hardware...\n");

    // This would be where you configure I/O ports, enable IRQs, etc.
    // Set up mouse, keyboard, audio initialization here.

    // For simplicity, skipping hardware setup code (usually done via I/O ports or BIOS)
}

void keyboard_init(void) {
    system_print("Initializing keyboard...\n");
    // Code for keyboard interrupt setup
    // You'd typically set up a keyboard interrupt (IRQ 1) handler here
}

int keyboard_read(void) {
    // Read a key press from the keyboard (polling or interrupt-driven)
    // For simplicity, this will simulate a key press
    if (keyboard_buffer[0] != 0) {
        int key = keyboard_buffer[0];
        keyboard_buffer[0] = 0;  // Clear the buffer
        return key;
    }
    return -1;  // No key pressed
}

void mouse_init(void) {
    system_print("Initializing mouse...\n");
    // Code for mouse initialization
    // Usually involves enabling mouse interrupts and setting mouse protocol (PS/2, USB)
}

void mouse_read(int* x, int* y, int* button_status) {
    // Read mouse position and button status (simple emulation here)
    *x = mouse_x;
    *y = mouse_y;
    *button_status = mouse_button_status;
}

void audio_init(void) {
    system_print("Initializing audio...\n");
    // Audio driver setup would be here
    // For simplicity, placeholder for actual audio initialization code
}

void audio_play_sound(const char* sound_file) {
    system_print("Playing sound: ");
    system_print(sound_file);  // Placeholder for actual sound-playing logic
}

