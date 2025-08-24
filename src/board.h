#ifndef BOARD
#define BOARD

#define TILES_NUMBER   288

#include <string.h>
#include <stdio.h>
#include <raylib.h>

extern int gameWidth;
extern int gameHeight;

typedef struct{
    Vector2 position;
    Texture2D sprite;
    bool isRevealed;
    bool hasBomb;
    bool hasFlag;
    char neighbourMines;
} tile;

extern tile tiles[TILES_NUMBER];
//extern RenderTexture2D boardFrame;

void InitBoard(int tileWidth,int _gameWidth, int _gameHeight);
void DrawBoard();

#endif