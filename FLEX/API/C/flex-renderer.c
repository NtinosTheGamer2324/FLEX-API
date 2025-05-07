#include "flex-renderer.h"

// Basic structures to simulate rendering objects (textboxes, buttons)
typedef struct {
    const char* label; // Button label
    int pressed;       // Button pressed state
} Button;

typedef struct {
    const char* placeholder; // Placeholder text for a textbox
    const char* text;        // Text input (empty for now)
} Textbox;

// Define a screen buffer (simulate memory for the screen with width and height)
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25
char screen_buffer[SCREEN_HEIGHT][SCREEN_WIDTH];

// Function to initialize the renderer
void renderer_init(void) {
    // Clear screen buffer
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            screen_buffer[i][j] = ' '; // Empty space (simulates a blank screen)
        }
    }
}

// Function to simulate setting a background image (for now, it's just filling the screen)
void renderer_set_background(const char* image_path) {
    // For now, simulate by filling the screen with a dot (could be an image later)
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            screen_buffer[i][j] = '.'; // Simulating a simple background
        }
    }
}

// Function to create a textbox (returns a pointer to the textbox object)
void* renderer_create_textbox(const char* placeholder) {
    // Create a textbox at a specific memory location (simplified for low-level OS)
    Textbox* textbox = (Textbox*)0x1000;  // Hardcoded memory address (this should be dynamic in your real OS)
    textbox->placeholder = placeholder;
    textbox->text = "";  // Empty text for now
    return textbox;
}

// Function to create a button (returns a pointer to the button object)
void* renderer_create_button(const char* label) {
    // Create a button at a specific memory location
    Button* button = (Button*)0x2000;  // Hardcoded address for simplicity
    button->label = label;
    button->pressed = 0; // Initial state: not pressed
    return button;
}

// Function to render the graphics on the screen (write to the simulated screen buffer)
void renderer_render(void) {
    // Simulate rendering the screen buffer (in a real OS, write to framebuffer)
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            // Directly output to console or framebuffer
            // Use low-level system calls to output characters (simulating output here)
            putchar(screen_buffer[i][j]); // Use direct I/O for screen output in a real system
        }
        putchar('\n'); // Newline after each row of pixels
    }
}

// Function to check if a button was pressed (simulated logic for button press)
int renderer_button_pressed(void* button) {
    Button* btn = (Button*)button;
    // For now, simulate button press (always returns 1 to simulate a press)
    btn->pressed = 1; // Simulate that the button is pressed
    return btn->pressed; // Return pressed state
}

// Function to get text from a textbox (return the current text from the textbox)
const char* renderer_get_text(void* textbox) {
    Textbox* txtbox = (Textbox*)textbox;
    return txtbox->text;  // Return the text entered in the textbox (empty for now)
}
