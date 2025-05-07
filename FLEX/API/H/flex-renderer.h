#ifndef FLEX_RENDERER_H
#define FLEX_RENDERER_H

// Initialization function for the renderer
void renderer_init(void);

// Function to set a background image (for now, we simulate it)
void renderer_set_background(const char* image_path);

// Function to create a textbox (returns a pointer to the textbox object)
void* renderer_create_textbox(const char* placeholder);

// Function to create a button (returns a pointer to the button object)
void* renderer_create_button(const char* label);

// Function to render the graphics on screen (simulating framebuffer write)
void renderer_render(void);

// Function to check if a button was pressed (checks simulated event)
int renderer_button_pressed(void* button);

// Function to get text from a textbox (returns text entered by user)
const char* renderer_get_text(void* textbox);

#endif // FLEX_RENDERER_H
