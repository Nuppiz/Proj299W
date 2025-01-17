#ifndef TEXT_H
#define TEXT_H

#include "SRC/SYS/Str_inp.h"
#include "Str_text.h"

void loadFont();
void loadFontNew();
void drawSymbol(int x, int y, int i, uint8_t color);
int  drawText(int x, int y, char* string, uint8_t color);
int  drawTextVGA(int x, int y, char* string, uint8_t color);
int  drawTextClipped(int x, int y, char* string, uint8_t color);
void drawMenuText();
void resetInput(TextInput_t* input);
void getCharacter(InputEvent_t* event, char* destination_str);
int handleTextInput(InputEvent_t event, TextInput_t* destination);

#endif/* TEXT */
