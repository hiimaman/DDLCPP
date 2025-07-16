#include "raylib.h"
#include "textbox.h"

Texture2D textbox;

// initialize the textbox
void init_textbox()
{
    textbox = LoadTexture("images/gui/textbox.png");
}

// draw the textbox
void draw_textbox(int screenWidth)
{
    DrawTexture(textbox, (screenWidth - textbox.width) / 2, 520, WHITE);
}

int textbox_width()
{
    return textbox.width;
}