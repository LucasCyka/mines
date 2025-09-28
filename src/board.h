#ifndef BOARD
#define BOARD

#define TILES_NUMBER   288
#define MINES_NUMBER   55

#include <string.h>
#include <stdio.h>
#include <raylib.h>
#include <raymath.h>

extern int gameWidth;
extern int gameHeight;
extern int tileWidth;

typedef struct{
    Vector2 position;
    Texture2D sprite;
    bool isRevealed;
    bool hasMine;
    bool hasFlag;
    bool isPressed;
    char neighbourMines;
} tile;

extern tile tiles[TILES_NUMBER];
extern int pressedTile;

//extern RenderTexture2D boardFrame;

void InitBoard(int _tileWidth,int _gameWidth, int _gameHeight);
void DrawBoard();
void PlaceFlags();
void RevealTiles();
void RevealMines();
int  getNeighbouringMines(int tileID);
int  GetRemainingMines();
bool InitTiles();
bool revealTileFrom(int tileID);
bool RevealFailed();
bool CheckFailure();

#endif