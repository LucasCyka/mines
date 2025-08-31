#ifndef UI
#define UI

#define BUTTONS_NUMBER 1

#include <stdbool.h>
#include <raylib.h>

typedef struct{
    int id;
    Rectangle rec;
    Texture2D texture;
    Texture2D pressedTexture;
    bool isPressed;
} button;

extern button buttons[BUTTONS_NUMBER];

void DrawButtons();
void InitUI(int _tileWidth, int _gameWidth);
void DrawUI(int _hiddenMines, int _elapsedTime);
bool IsStartPressed();

#endif