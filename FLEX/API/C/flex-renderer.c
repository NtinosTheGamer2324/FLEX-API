#include "flex-renderer.h"

// Define a basic structure to simulate rendering objects (e.g., buttons, textboxes)
typedef struct {
    const char* label;
    int pressed;
} Button;

typedef struct {
    const char* placeholder;
    const char* text;
} Textbox;

// Simulate a screen buffer where we store pixel data (this is a very simplified version)
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25
char screen_buffer[SCREEN_HEIGHT][SCREEN_WIDTH];

// Function to initialize the rendering system (simply clears the screen buffer)
void renderer_init(void) {
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            screen_buffer[i][j] = ' ';
        }
    }
}

// Function to simulate setting a background (in this case, just filling the screen with a character)
void renderer_set_background(const char* image_path) {
    // In a real OS, you’d load an image here, but for simplicity, we just simulate it
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            screen_buffer[i][j] = '.';
        }
    }
}

// Function to simulate creating a textbox (only stores the placeholder text)
void* renderer_create_textbox(const char* placeholder) {
    Textbox* textbox = (Textbox*)0x1000;  // Hardcoded address for simplicity (Replace with actual memory allocation)
    textbox->placeholder = placeholder;
    textbox->text = "";
    return textbox;
}

// Function to simulate creating a button (stores the label and a "pressed" state)
void* renderer_create_button(const char* label) {
    Button* button = (Button*)0x2000;  // Hardcoded address for simplicity (Replace with actual memory allocation)
    button->label = label;
    button->pressed = 0;
    return button;
}

// Function to render the UI (just prints the screen buffer to the console)
void renderer_render(void) {
    // For simplicity, simulate drawing the screen buffer
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            // Print each "pixel" or character in the screen buffer
            // In a real OS, you'd write to the framebuffer or terminal
            // For now, we're just "printing" to the console
            putchar(screen_buffer[i][j]);
        }
        putchar('\n');
    }
}

// Function to simulate checking if a button was pressed (always returns 1 for simplicity)
int renderer_button_pressed(void* button) {
    Button* btn = (Button*)button;
    // For now, simulate the button being pressed
    btn->pressed = 1;
    return btn->pressed;
}

// Function to simulate getting the text from a textbox
const char* renderer_get_text(void* textbox) {
    Textbox* txtbox = (Textbox*)textbox;
    return txtbox->text;  // In a real system, this would return user input from a keyboard
}
