#include "board.h"
#include "graphics.h"


//RenderTexture2D boardFrame;
tile tiles[TILES_NUMBER];
int pressedTile = 0;

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
            tiles[id].hasMine   = false;

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
    Vector2 pos = {GetMousePosition().x,GetMousePosition().y};
    pos.x /= (float)GetScreenWidth()/gameWidth;
    pos.y /= (float)GetScreenHeight()/gameHeight;

    Rectangle mouseRec = {pos.x,pos.y,5,5};

    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
        bool pressed  = false;
        for (int id = 0; id < TILES_NUMBER; id++){
            tiles[id].sprite = hiddenTileTex;

            if ( CheckCollisionRecs((Rectangle){tiles[id].position.x,tiles[id].position.y,16,16},mouseRec) && !pressed){
                tiles[id].sprite = revealedTileTex;
                pressed          = true;
            }

        }

    }else if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON)){
        for (int id = 0; id < TILES_NUMBER; id++){
            tiles[id].sprite = hiddenTileTex;

            if ( CheckCollisionRecs((Rectangle){tiles[id].position.x,tiles[id].position.y,16,16},mouseRec)){
                
                int mines = 0;
                
                while(mines != MINES_NUMBER){
                    int randomId = GetRandomValue(0,TILES_NUMBER-1);
                    
                    if(randomId == id){continue;}

                    if(!tiles[randomId].hasMine){
                        tiles[randomId].hasMine = true;
                        mines++;
                    }
                }

                tiles[id].sprite = revealedTileTex;
                revealTileFrom(id);
                return true;
            }

        }
    }

    return false;
}

int getTileNeighbours(int tileID){

}

bool revealTileFrom(int tileID){


    return false;
}