#include "flex-renderer.h"
#include "FLEX-SYSTEM.h"
#include "flexFAT.h"

// Function to set the background image
void render_setbackimg(const char* img_path) {
    void* image = load_image(img_path);  // Load the image
    // Assuming there's some system function that actually sets the image as background
    system_set_background(image);
}

// Function to create a textbox (this is a mockup for now)
void render_create_TEXTBOX(const char* placeholder) {
    // Assuming we have a system function that creates a textbox on screen
    system_create_textbox(placeholder);
}

// Function to create a button (this is a mockup for now)
void render_create_BUTTON(const char* label) {
    // Assuming we have a system function that creates a button on screen
    system_create_button(label);
}

// Function to update the screen rendering (checking for interactions, etc.)
void render_update(void) {
    // Assuming this function is called in the main loop to update the graphics on screen
    system_render();
}

// Function to render a simple text on the screen
void render_text(const char* text) {
    // Assuming this function draws text on the screen
    system_draw_text(text);
}

// Function to render a spacer (an empty area between UI elements)
void render_spacer(void) {
    // This might just add an empty space between UI components
    system_add_spacer();
}

// Utility function to load images from the system
void* load_image(const char* path) {
    // Load image using flexFAT or any image loading utility
    return flex_fat(path);  // mock function to load image from flexFAT (assuming it exists)
}
