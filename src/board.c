#include "board.h"
#include "graphics.h"


//RenderTexture2D boardFrame;
tile tiles[TILES_NUMBER];
int pressedTile = 0;
int tileWidth   = 0;

void InitBoard(int _tileWidth,int _gameWidth, int _gameHeight){
    gameWidth  = _gameWidth;
    gameHeight = _gameHeight;
    tileWidth  = _tileWidth;
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

int getNeighbouringMines(int tileID){


    return 0;
}

bool revealTileFrom(int tileID){

    int nMines = 0;
    Vector2 tpos = tiles[tileID].position;

    tiles[tileID].isRevealed = true;

    Vector2 neighbourPos[8] = {
        (Vector2) {tpos.x+tileWidth,tpos.y},
        (Vector2) {tpos.x-tileWidth,tpos.y},
        (Vector2) {tpos.x,tpos.y+tileWidth},
        (Vector2) {tpos.x,tpos.y-tileWidth},
        (Vector2) {tpos.x+tileWidth,tpos.y+tileWidth},
        (Vector2) {tpos.x-tileWidth,tpos.y-tileWidth},
        (Vector2) {tpos.x+tileWidth,tpos.y-tileWidth},
        (Vector2) {tpos.x-tileWidth,tpos.y+tileWidth}
    };

    for(int i = 0; i < TILES_NUMBER; i++){

        if(tiles[i].isRevealed){continue;}

        for(int n = 0; n < 8; n++){
            if (FloatEquals(tiles[i].position.x, neighbourPos[n].x) && FloatEquals(tiles[i].position.y, neighbourPos[n].y)){
                if (tiles[i].hasMine){nMines++;}
                //else{revealTileFrom(i);}
            }
        }

    }

    if(nMines == 0){
        tiles[tileID].sprite = revealedTileTex;

        for(int i = 0; i < TILES_NUMBER; i++){

            if(tiles[i].isRevealed){continue;}

            for(int n = 0; n < 8; n++){
                if (FloatEquals(tiles[i].position.x, neighbourPos[n].x) && FloatEquals(tiles[i].position.y, neighbourPos[n].y)){
                    revealTileFrom(i);
                }
            }

        }

    }

    if(nMines == 1){tiles[tileID].sprite = mine1TileTex;}
    if(nMines == 2){tiles[tileID].sprite = mine2TileTex;}
    if(nMines == 3){tiles[tileID].sprite = mine3TileTex;}
    if(nMines == 4){tiles[tileID].sprite = mine4TileTex;}
    if(nMines == 5){tiles[tileID].sprite = mine5TileTex;}
    if(nMines == 6){tiles[tileID].sprite = mine6TileTex;}
    if(nMines == 7){tiles[tileID].sprite = mine7TileTex;}
    if(nMines == 8){tiles[tileID].sprite = mine8TileTex;}


    return false;
}