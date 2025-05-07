#ifndef FLEX_RENDERER_H
#define FLEX_RENDERER_H

// Function to initialize the rendering system
void renderer_init(void);

// Function to set the background image of the UI
void renderer_set_background(const char* image_path);

// Function to create a text box for user input
void* renderer_create_textbox(const char* placeholder);

// Function to create a button
void* renderer_create_button(const char* label);

// Function to render the GUI
void renderer_render(void);

// Function to check if a button has been pressed
int renderer_button_pressed(void* button);

// Function to get the text from a textbox
const char* renderer_get_text(void* textbox);

#endif // FLEX_RENDERER_H
