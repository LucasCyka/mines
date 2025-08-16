#include <raylib.h>
#include <raymath.h>

enum GAME_STATE {RUNNING,PAUSED};

typedef struct
{
    Vector2 position;
    char isRevealed;
    char hasBomb;
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