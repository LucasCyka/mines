#ifndef UI
#define UI

#define BUTTONS_NUMBER 1

#include <stdbool.h>
#include <raylib.h>

typedef struct{
    Rectangle rec;
    Texture2D texture;
    bool isPressed;
} button;

extern button buttons[BUTTONS_NUMBER];

void DrawButtons();
void InitUI(int _tileWidth, int _gameWidth);
void DrawUI(int _hiddenMines, int _elapsedTime);




#endif