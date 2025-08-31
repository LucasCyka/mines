#include "board.h"
#include "graphics.h"


//RenderTexture2D boardFrame;
tile tiles[TILES_NUMBER];
tile pressedTile;

void InitBoard(int tileWidth,int _gameWidth, int _gameHeight){
    gameWidth  = _gameWidth;
    gameHeight = _gameHeight;
    int id = 0;
    for (int y = 0; y < 12; y++){

        for(int x = 0; x < 24; x++){
            tiles[id] = (tile) {};
            tiles[id].position  = (Vector2) {x*tileWidth+tileWidth,y*tileWidth+32};
            tiles[id].sprite    = hiddenTileTex;
            tiles[id].isPressed = false;

            id++;
        }
    }
}

void DrawBoard(){
        for(int i = 0; i < TILES_NUMBER; i++){
            tile cTile = tiles[i];
            DrawTexture(cTile.sprite,cTile.position.x,cTile.position.y,WHITE);

        }
}

bool InitTiles(){
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        Vector2 pos = {GetMousePosition().x,GetMousePosition().y};
        pos.x /= (float)GetScreenWidth()/gameWidth;
        pos.y /= (float)GetScreenHeight()/gameHeight;

        Rectangle mouseRec = {pos.x,pos.y,5,5};
        
        for (int id = 0; id < TILES_NUMBER; id++){

            if ( CheckCollisionRecs((Rectangle){tiles[id].position.x,tiles[id].position.y,16,16},mouseRec)){
                
                tiles[id].sprite = revealedTileTex;
                //TODO: randomize mines 
                break;
            }

        }

    }

    return false;
}