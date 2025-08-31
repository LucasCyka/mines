#ifndef BOARD
#define BOARD

#define TILES_NUMBER   288

#include <string.h>
#include <stdio.h>
#include <raylib.h>
#include <raymath.h>

extern int gameWidth;
extern int gameHeight;

typedef struct{
    Vector2 position;
    Texture2D sprite;
    bool isRevealed;
    bool hasBomb;
    bool hasFlag;
    bool isPressed;
    char neighbourMines;
} tile;

extern tile tiles[TILES_NUMBER];
extern tile pressedTile;

//extern RenderTexture2D boardFrame;

void InitBoard(int tileWidth,int _gameWidth, int _gameHeight);
void DrawBoard();
bool InitTiles();

#endif