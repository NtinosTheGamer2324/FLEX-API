#include "flex-system.h"
#include <stdint.h>
#include <stddef.h>

#define KEYBOARD_DATA_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64

#define MOUSE_DATA_PORT 0x60
#define MOUSE_STATUS_PORT 0x64

#define PIT_COMMAND_PORT 0x43
#define PIT_CHANNEL0_PORT 0x40

volatile uint8_t keyboard_buffer[256];
volatile int mouse_x = 0, mouse_y = 0, mouse_button_status = 0;
volatile unsigned long uptime = 0;

void system_halt(void) {
    while (1);  // Halt the system indefinitely
}

void system_init_hardware(void) {
    // Initialize hardware components like PIT, keyboard, mouse, audio, etc.
    outb(PIT_COMMAND_PORT, 0x36);  // Set PIT mode
    outb(PIT_CHANNEL0_PORT, 0xFF); // Low byte of PIT divisor
    outb(PIT_CHANNEL0_PORT, 0xFF); // High byte of PIT divisor

    keyboard_init();
    mouse_init();
    audio_init();
}

void keyboard_init(void) {
    // Enable IRQ1 for the keyboard
    outb(0x20, 0x20);  // End of interrupt for IRQ1
}

int keyboard_read(void) {
    if (inb(KEYBOARD_STATUS_PORT) & 1) {
        return inb(KEYBOARD_DATA_PORT);  // Read the scan code from the keyboard
    }
    return -1;  // No key pressed
}

void mouse_init(void) {
    // Enable IRQ12 for the mouse
    outb(0x20, 0x20);  // End of interrupt for IRQ12
}

void mouse_read(int* x, int* y, int* button_status) {
    if (inb(MOUSE_STATUS_PORT) & 1) {
        *x = inb(MOUSE_DATA_PORT);
        *y = inb(MOUSE_DATA_PORT);
        *button_status = inb(MOUSE_DATA_PORT);
    }
}

void audio_init(void) {
    // Initialize audio system (using PIT for tone generation)
}

void audio_play_sound(uint16_t frequency, uint32_t duration) {
    uint32_t divisor = 1193180 / frequency;  // PIT divisor calculation

    outb(PIT_COMMAND_PORT, 0xB6);  // Command to set speaker mode
    outb(PIT_CHANNEL0_PORT, (uint8_t)(divisor & 0xFF));  // Send low byte
    outb(PIT_CHANNEL0_PORT, (uint8_t)((divisor >> 8) & 0xFF));  // Send high byte

    // Wait for the specified duration (simple delay loop)
    for (uint32_t i = 0; i < duration * 1000; i++) {
        asm volatile ("nop");
    }

    // Stop the sound
    outb(PIT_COMMAND_PORT, 0x36);  // Reset PIT configuration
}
