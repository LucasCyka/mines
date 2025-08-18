#define TILES_NUMBER 288

#include <stdio.h>
#include <stdbool.h>
#include <raylib.h>
#include <raymath.h>

enum GAME_STATE {RUNNING,PAUSED};

typedef struct{
    Vector2 position;
    Texture2D sprite;
    bool isRevealed;
    bool hasBomb;
    bool hasFlag;
    char neighbourBombs;
} tile;

int windowWidth       = 800;
int windowHeight      = 450;

const int gameWidth   = 416;
const int gameHeight  = 234;

RenderTexture2D boardFrame;
tile tiles[TILES_NUMBER];

//textures
Texture2D hiddenTileTex;
Texture2D frame1;
Texture2D frame2;

void InitBoard();
void LoadTextures();
void DrawBoard();

int main(){

    InitWindow(windowWidth,windowHeight,"Mines");
    LoadTextures();
    InitBoard();
    float scale = (float) windowWidth/gameWidth;
    SetTargetFPS(30);

    while (!WindowShouldClose())
    {

        DrawBoard();

        BeginDrawing();

            ClearBackground(PURPLE);

            DrawTexturePro(boardFrame.texture,
        (Rectangle) {0.0f,0.0f,boardFrame.texture.width, -boardFrame.texture.height},
        (Rectangle){windowWidth - ((float)gameWidth*scale), windowHeight - ((float)gameHeight*scale),(float)gameWidth*scale,(float)gameHeight*scale,
        },(Vector2){0,0},0.0f,WHITE);

            //DrawTexture(boardFrame.texture,0,0,WHITE);

            //DrawTexture(boardFrame.texture,0,200,WHITE);

        EndDrawing();
    }
    
    CloseWindow();

    return 0;
}

void InitBoard(){
    boardFrame = LoadRenderTexture(gameWidth, gameHeight);
    //SetTextureFilter(boardFrame.texture,TEXTURE_FILTER_TRILINEAR)

    int id = 0;
    for (int y = 0; y < 12; y++){

        for(int x = 0; x < 24; x++){
            tiles[id] = (tile) {};
            tiles[id].position = (Vector2) {x*16+16,y*16+32};
            tiles[id].sprite   = hiddenTileTex;

            id++;
        }
    }
}

void LoadTextures(){
    hiddenTileTex = LoadTexture("../resources/tileHidden.png"); 
    frame1        = LoadTexture("../resources/frame1.png");
    frame2        = LoadTexture("../resources/frame2.png");
}

void DrawBoard(){

    BeginTextureMode(boardFrame);

        DrawTexture(frame1,0,0,WHITE);
        DrawTexture(frame2,0,0,WHITE);

        for(int i = 0; i < TILES_NUMBER; i++){
            tile cTile = tiles[i];
            DrawTexture(cTile.sprite,cTile.position.x,cTile.position.y,WHITE);

        }


    EndTextureMode();
}