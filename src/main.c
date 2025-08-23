#define TILES_NUMBER   288
#define BUTTONS_NUMBER 1
#define TILE_WIDTH     16
#define TILE_HEIGHT    16

#include <stdio.h>
#include <stdbool.h>
#include <raylib.h>
#include <raymath.h>
#include <string.h>

enum GAME_STATE {RUNNING,PAUSED};

typedef struct{
    Vector2 position;
    Texture2D sprite;
    bool isRevealed;
    bool hasBomb;
    bool hasFlag;
    char neighbourMines;
} tile;

typedef struct{
    Rectangle rec;
    Texture2D texture;
    bool isPressed;
} button;


int windowWidth       = 800;
int windowHeight      = 450;
int elapsedTime       = 123;
int hiddenNines       = 321; //hidden

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
Texture2D scoreNumbers[10];

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

    //score
    
}

void LoadTextures(){

    if (!DirectoryExists(strcat(GetWorkingDirectory(),"/resources"))){
        for(int i =0; i <2; i++){
            
            if (!ChangeDirectory(GetPrevDirectoryPath(GetWorkingDirectory()))){
                printf("resource directory not found. Failure to change working directory.");
            }
            if ( DirectoryExists(strcat(GetWorkingDirectory(),"/resources"))) {
                break;
            }
        }

    }

    //TODO: load from .json?
    hiddenTileTex = LoadTexture("resources/tileHidden.png"); 
    frame1        = LoadTexture("resources/frame1.png");
    frame2        = LoadTexture("resources/frame2.png");
    frame3        = LoadTexture("resources/frame3.png");
    smilling      = LoadTexture("resources/btn_smiling.png");

    scoreNumbers[0] = LoadTexture("resources/ScoreNumbers1.png"); 
    scoreNumbers[1] = LoadTexture("resources/ScoreNumbers2.png"); 
    scoreNumbers[2] = LoadTexture("resources/ScoreNumbers3.png"); 
    scoreNumbers[3] = LoadTexture("resources/ScoreNumbers4.png"); 
    scoreNumbers[4] = LoadTexture("resources/ScoreNumbers5.png"); 
    scoreNumbers[5] = LoadTexture("resources/ScoreNumbers6.png"); 
    scoreNumbers[6] = LoadTexture("resources/ScoreNumbers7.png"); 
    scoreNumbers[7] = LoadTexture("resources/ScoreNumbers8.png"); 
    scoreNumbers[8] = LoadTexture("resources/ScoreNumbers9.png"); 
    scoreNumbers[9] = LoadTexture("resources/ScoreNumbers10.png"); 
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

        //tiles
        for(int i = 0; i < TILES_NUMBER; i++){
            tile cTile = tiles[i];
            DrawTexture(cTile.sprite,cTile.position.x,cTile.position.y,WHITE);

        }

        //number of mines counter
        //1s
        DrawTexture(scoreNumbers[hiddenNines % 10],37,6,WHITE);
        //10s
        DrawTexture(scoreNumbers[(int) (hiddenNines/10) % 10],29,6,WHITE);
        //100s
        DrawTexture(scoreNumbers[(int) (hiddenNines/100) % 10],21,6,WHITE);

        //timer
        //1s
        DrawTexture(scoreNumbers[elapsedTime % 10],386,6,WHITE);
        //10s
        DrawTexture(scoreNumbers[(int) (elapsedTime/10) % 10],379,6,WHITE);
        //100s
        DrawTexture(scoreNumbers[(int) (elapsedTime/100) % 10],371,6,WHITE);

    EndTextureMode();
}