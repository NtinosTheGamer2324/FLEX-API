#ifndef FLEX_SYSTEM_H
#define FLEX_SYSTEM_H

// Function to set the background image
void system_set_background(void* image);

// Function to create a textbox
void system_create_textbox(const char* placeholder);

// Function to create a button
void system_create_button(const char* label);

// Function to render the system (main loop)
void system_render(void);

// Function to draw text on the screen
void system_draw_text(const char* text);

// Function to add a spacer between UI elements
void system_add_spacer(void);

#endif // FLEX_SYSTEM_H
