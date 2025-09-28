#include "board.h"
#include "graphics.h"

//warning: very bad code ahead
//coded while drunk at saturday nights
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

void PlaceFlags(){
    if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)){

        Vector2 pos = {GetMousePosition().x,GetMousePosition().y};
        pos.x /= (float)GetScreenWidth()/gameWidth;
        pos.y /= (float)GetScreenHeight()/gameHeight;

        Rectangle mouseRec = {pos.x,pos.y,5,5};

        for (int id = 0; id < TILES_NUMBER; id++){
            if (tiles[id].isRevealed){continue;}

            if ( CheckCollisionRecs((Rectangle){tiles[id].position.x,tiles[id].position.y,16,16},mouseRec)){
                
                if(tiles[id].hasFlag){
                    tiles[id].sprite = hiddenTileTex;
                    tiles[id].hasFlag = false;
                } else {
                    if(GetRemainingMines() <= 0){break;}
                    tiles[id].sprite = hiddenTileFlagTex;
                    tiles[id].hasFlag = true;
                }

                break;
            }

        }

    }
}

int  GetRemainingMines(){

    int mines = 0;
    for(int id = 0; id < TILES_NUMBER; id++){
        if (tiles[id].hasFlag){mines++;}
    }

    return MINES_NUMBER - mines;
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

    //TODO: array
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

void RevealTiles(){
    Vector2 pos = {GetMousePosition().x,GetMousePosition().y};
    pos.x /= (float)GetScreenWidth()/gameWidth;
    pos.y /= (float)GetScreenHeight()/gameHeight;
    Rectangle mouseRec = {pos.x,pos.y,5,5};

    if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){ //indication

        for (int id = 0; id < TILES_NUMBER; id++){
            if (tiles[id].hasFlag){continue;}

            if ( CheckCollisionRecs((Rectangle){tiles[id].position.x,tiles[id].position.y,16,16},mouseRec)){
                
                int neighboursNum = 0;
                Vector2 tpos = tiles[id].position;

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

                if(tiles[id].isRevealed){

                    for (int nTile = 0; nTile < TILES_NUMBER; nTile++){

                        for (int n = 0; n < 8; n++){
                            if(FloatEquals(neighbourPos[n].x,tiles[nTile].position.x) && FloatEquals(neighbourPos[n].y,tiles[nTile].position.y)){
                                neighboursNum++;
                                if(!tiles[nTile].isRevealed && !tiles[nTile].hasFlag){
                                    tiles[nTile].sprite = revealedTileTex;
                                }

                            }
                        }

                    }

                }else{
                    tiles[id].sprite = revealedTileTex;
                    for(int ii = 0; ii < TILES_NUMBER; ii++){
                        if(tiles[ii].hasFlag || ii == id || tiles[ii].isRevealed) {continue;}

                        tiles[ii].sprite = hiddenTileTex;
                    }

                    break;
                }
             
                for(int i=0; i< TILES_NUMBER; i++){
                    bool isNeighbour = false;
                    if(tiles[i].isRevealed || tiles[i].hasFlag) {continue;}
                    for(int y=0; y < 8; y++){
                        if(FloatEquals(neighbourPos[y].x,tiles[i].position.x) && FloatEquals(neighbourPos[y].y,tiles[i].position.y)){
                            isNeighbour = true;
                        }
                    }
                    if(!isNeighbour) {tiles[i].sprite = hiddenTileTex;}
                }

            }
            //break;

         }

    }else if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){

        Vector2 pos = {GetMousePosition().x,GetMousePosition().y};
        pos.x /= (float)GetScreenWidth()/gameWidth;
        pos.y /= (float)GetScreenHeight()/gameHeight;
        Rectangle mouseRec = {pos.x,pos.y,5,5};

        for (int i = 0; i < TILES_NUMBER; i++){
            if(tiles[i].hasFlag) {continue;}

            if(!tiles[i].isRevealed){
                tiles[i].sprite = hiddenTileTex;
            }

             if ( CheckCollisionRecs((Rectangle){tiles[i].position.x,tiles[i].position.y,16,16},mouseRec)){

                if(!tiles[i].isRevealed && !tiles[i].hasMine){
                    revealTileFrom(i);
                    break;
                }

            }

        }
    }

}

bool RevealFailed(){




    return false;
}