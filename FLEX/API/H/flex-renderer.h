#ifndef FLEX_RENDERER_H
#define FLEX_RENDERER_H

// Include necessary headers
#include "FLEX-SYSTEM.h"
#include "flexFAT.h"

// Function declarations for rendering
void render_setbackimg(const char* img_path);
void render_create_TEXTBOX(const char* placeholder);
void render_create_BUTTON(const char* label);
void render_update(void);
void render_text(const char* text);
void render_spacer(void);

// Utility function to load images
void* load_image(const char* path);

#endif // FLEX_RENDERER_H

