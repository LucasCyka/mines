#include <raylib.h>
#include <raymath.h>
#include <stdbool.h>

enum GAME_STATE {RUNNING,PAUSED};

typedef struct
{
    Vector2 position;
    bool isRevealed;
    bool hasBomb;
    bool hasFlag;
} tile;


int main(){

    InitWindow(800,450,"Mines");

    SetTargetFPS(30);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        EndDrawing();
    }
    
    CloseWindow();

    return 0;
}