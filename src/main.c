#define TILES_NUMBER   288
#define BUTTONS_NUMBER 1
#define TILE_WIDTH     16
#define TILE_HEIGHT    16

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

typedef struct{
    Rectangle rec;
    Texture2D texture;
    bool isPressed;
} button;


int windowWidth       = 800;
int windowHeight      = 450;

const int gameWidth   = 416;
const int gameHeight  = 234;

RenderTexture2D boardFrame;
tile tiles[TILES_NUMBER];
button buttons[10];

//textures
Texture2D hiddenTileTex;
Texture2D frame1;
Texture2D frame2;
Texture2D frame3;
Texture2D smilling;

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

    //tiles
    int id = 0;
    for (int y = 0; y < 12; y++){

        for(int x = 0; x < 24; x++){
            tiles[id] = (tile) {};
            tiles[id].position = (Vector2) {x*TILE_WIDTH+TILE_WIDTH,y*TILE_WIDTH+32};
            tiles[id].sprite   = hiddenTileTex;

            id++;
        }
    }

    //buttons
    button btn1;
    btn1.rec       = (Rectangle) { gameWidth/2-TILE_WIDTH, 4, smilling.width,smilling.height };
    btn1.texture   = smilling;
    btn1.isPressed = false;
    buttons[0] = btn1;
}

void LoadTextures(){
    hiddenTileTex = LoadTexture("../resources/tileHidden.png"); 
    frame1        = LoadTexture("../resources/frame1.png");
    frame2        = LoadTexture("../resources/frame2.png");
    frame3        = LoadTexture("../resources/frame3.png");
    smilling      = LoadTexture("../resources/btn_smiling.png");
}

void DrawBoard(){

    BeginTextureMode(boardFrame);

        //frames
        DrawTexture(frame1,0,0,WHITE);
        DrawTexture(frame2,0,0,WHITE);
        DrawTexture(frame3,0,0,WHITE);

        //buttons
        for (int i =0; i < BUTTONS_NUMBER; i++){
            button btn = buttons[i];

            DrawTexture(btn.texture,btn.rec.x,btn.rec.y,WHITE);
        }

        //counters

        for(int i = 0; i < TILES_NUMBER; i++){
            tile cTile = tiles[i];
            DrawTexture(cTile.sprite,cTile.position.x,cTile.position.y,WHITE);

        }


    EndTextureMode();
}