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

enum GAME_STATE {STARTING,RUNNING,WINNING,LOSING,QUITTING};

int windowWidth       = 800;
int windowHeight      = 450;
int elapsedTime       = 0;
//int hiddenMines       = 321; 
int gameWidth         = 416;
int gameHeight        = 234;
int _frames           = 0;

enum GAME_STATE currentState = STARTING;
enum GAME_STATE nextState    = STARTING;

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
        

        switch (currentState)
        {
        case STARTING:
            if (InitTiles()){
                currentState = RUNNING;
            }

            break;
        case RUNNING:
            _frames++;
            if(_frames % 30 == 0){
                _frames = 0;
                elapsedTime++;
            }
            
            PlaceFlags();
            RevealTiles();
            if (CheckFailure()){
                currentState = LOSING;
            }

            break;
        case WINNING:
            break;
        
        case LOSING:
            RevealMines();
            break;
        
        case QUITTING:
            break;

        default:
            break;
        }


        BeginTextureMode(boardFrame);

            DrawBoard();
            DrawUI(GetRemainingMines(),elapsedTime);
        
        EndTextureMode();

        BeginDrawing();

            ClearBackground(PURPLE);
            
            DrawTexturePro(boardFrame.texture,
        (Rectangle) {0.0f,0.0f,boardFrame.texture.width, -boardFrame.texture.height},
        (Rectangle){windowWidth - ((float)gameWidth*scale), windowHeight - ((float)gameHeight*scale),(float)gameWidth*scale,(float)gameHeight*scale,
        },(Vector2){0,0},0.0f,WHITE);


            //DrawText(TextFormat("Mouse: %i, %i",(int)GetMousePosition().x,(int)gameMouse.x),0,0,24,WHITE);
        EndDrawing();
    }
    
    CloseWindow();

    return 0;
}
