#include "board.h"
#include "graphics.h"


//RenderTexture2D boardFrame;
tile tiles[TILES_NUMBER];

void InitBoard(int tileWidth,int _gameWidth, int _gameHeight){

    int id = 0;
    for (int y = 0; y < 12; y++){

        for(int x = 0; x < 24; x++){
            tiles[id] = (tile) {};
            tiles[id].position = (Vector2) {x*tileWidth+tileWidth,y*tileWidth+32};
            tiles[id].sprite   = hiddenTileTex;

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