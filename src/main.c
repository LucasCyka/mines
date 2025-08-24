#define TILE_WIDTH     16
#define TILE_HEIGHT    16

#include <stdio.h>
#include <stdbool.h>
#include <raylib.h>
#include <raymath.h>
#include <string.h>
#include "board.h"
#include "ui.h"
#include "graphics.h"

enum GAME_STATE {RUNNING,PAUSED,OVER};

int windowWidth       = 800;
int windowHeight      = 450;
int elapsedTime       = 123;
int hiddenMines       = 321; 
int gameWidth         = 416;
int gameHeight        = 234;

RenderTexture2D boardFrame;


int main(){

    InitWindow(windowWidth,windowHeight,"Mines");
    LoadTextures();
    boardFrame = LoadRenderTexture(gameWidth, gameHeight);
    InitBoard(TILE_WIDTH,gameWidth,gameHeight);
    InitUI(TILE_WIDTH,gameWidth);
    float scale = (float) windowWidth/gameWidth;
    SetTargetFPS(30);
    
    while (!WindowShouldClose())
    {

        BeginTextureMode(boardFrame);

            DrawBoard();
            DrawUI(hiddenMines,elapsedTime);
        
        EndTextureMode();

        BeginDrawing();

            ClearBackground(PURPLE);
            
            DrawTexturePro(boardFrame.texture,
        (Rectangle) {0.0f,0.0f,boardFrame.texture.width, -boardFrame.texture.height},
        (Rectangle){windowWidth - ((float)gameWidth*scale), windowHeight - ((float)gameHeight*scale),(float)gameWidth*scale,(float)gameHeight*scale,
        },(Vector2){0,0},0.0f,WHITE);

        
        EndDrawing();
    }
    
    CloseWindow();

    return 0;
}
