#include "flex-system.h"
#include <stdint.h>
#include <stddef.h>

#define KEYBOARD_DATA_PORT 0x60
#define KEYBOARD_STATUS_PORT 0x64

#define MOUSE_DATA_PORT 0x60
#define MOUSE_STATUS_PORT 0x64

#define PIT_COMMAND_PORT 0x43
#define PIT_CHANNEL0_PORT 0x40

// Declare global variables to store mouse position and button status
volatile uint8_t keyboard_buffer[256];
volatile int mouse_x = 0, mouse_y = 0, mouse_button_status = 0;
volatile unsigned long uptime = 0;

// Initialize the system and hardware devices
void system_init(void) {
    system_init_hardware();
    keyboard_init();
    mouse_init();
    audio_init();
}

// Start the system and enter the main loop
void system_start(void) {
    system_print("System Started...\n");

    while (1) {
        uptime++;  // Track system uptime

        // Handle Keyboard Input
        int key = keyboard_read();
        if (key != -1) {
            system_print("Key pressed: ");
            char msg[3] = {(char)key, '\0', '\0'};
            system_print(msg);
        }

        // Handle Mouse Input
        int x, y, button;
        mouse_read(&x, &y, &button);
        char pos[50];
        sprintf(pos, "Mouse position: X:%d Y:%d Buttons: %d\n", x, y, button);
        system_print(pos);

        // Handle Audio Output (example with a tone)
        audio_play_sound(440, 500);  // Example frequency and duration
    }
}

// Halt the system
void system_halt(void) {
    system_print("System Halted...\n");
    while (1);  // Infinite loop to halt system
}

// Initialize hardware devices and components
void system_init_hardware(void) {
    system_print("Initializing Hardware...\n");

    // Initialize PIT for system timing
    outb(PIT_COMMAND_PORT, 0x36);  // Set PIT mode to continuous mode
    outb(PIT_CHANNEL0_PORT, 0xFF); // Low byte of PIT divisor
    outb(PIT_CHANNEL0_PORT, 0xFF); // High byte of PIT divisor

    // Initialize Keyboard, Mouse, and Audio devices
    keyboard_init();
    mouse_init();
    audio_init();
}

// Print a message to the system output (console, framebuffer, etc.)
void system_print(const char* msg) {
    // Assume a custom print function using low-level I/O or framebuffer
    // Here we use `printf` as a placeholder, replace with actual print function
    printf("%s", msg);
}

// Implement a delay in milliseconds (approximate)
void delay(uint32_t milliseconds) {
    uint32_t i;
    for (i = 0; i < milliseconds * 1000; i++) {
        asm volatile ("nop");
    }
}

// Initialize the keyboard driver
void keyboard_init(void) {
    system_print("Initializing Keyboard...\n");
    outb(0x20, 0x20);  // End of interrupt for IRQ1 (keyboard)
}

// Read keyboard input from the keyboard buffer
int keyboard_read(void) {
    if (inb(KEYBOARD_STATUS_PORT) & 1) {
        return inb(KEYBOARD_DATA_PORT);  // Return the scan code
    }
    return -1;  // No key pressed
}

// Interrupt handler for keyboard events (to be called by IRQ handler)
void keyboard_interrupt_handler(void) {
    // Handle the keyboard interrupt (IRQ1) here
    int key = keyboard_read();
    if (key != -1) {
        // Process the key (e.g., store in buffer, process input)
    }
}

// Initialize the mouse driver
void mouse_init(void) {
    system_print("Initializing Mouse...\n");
    outb(0x20, 0x20);  // End of interrupt for IRQ12 (mouse)
}

// Read mouse input and return x, y positions, and button status
void mouse_read(int* x, int* y, int* button_status) {
    if (inb(MOUSE_STATUS_PORT) & 1) {
        *x = inb(MOUSE_DATA_PORT);
        *y = inb(MOUSE_DATA_PORT);
        *button_status = inb(MOUSE_DATA_PORT);
    }
}

// Interrupt handler for mouse events (to be called by IRQ handler)
void mouse_interrupt_handler(void) {
    // Handle mouse input here
    int x, y, button;
    mouse_read(&x, &y, &button);
    // Process the mouse input (e.g., update cursor position)
}

// Initialize the audio driver
void audio_init(void) {
    system_print("Initializing Audio...\n");
    // Initialize the audio system here (for example, setting up the audio controller)
}

// Play a sound with a given frequency and duration
void audio_play_sound(uint16_t frequency, uint32_t duration) {
    // Send commands to the audio hardware to play the sound
    // This would typically involve setting up a timer and a speaker
    system_print("Playing sound: Frequency ");
    char freq[10];
    sprintf(freq, "%d", frequency);
    system_print(freq);
    system_print(" for ");
    char dur[10];
    sprintf(dur, "%d", duration);
    system_print(dur);
    system_print(" ms\n");
}

// Interrupt handler for audio events (e.g., sound playback completion)
void audio_interrupt_handler(void) {
    // Handle audio interrupt, like sound playback complete
    system_print("Audio interrupt handled\n");
}
