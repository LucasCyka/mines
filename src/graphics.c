#include "graphics.h"

//textures
Texture2D hiddenTileTex;
Texture2D hiddenTileFlagTex;
Texture2D revealedTileTex;
Texture2D mine1TileTex;
Texture2D mine2TileTex;
Texture2D mine3TileTex;
Texture2D mine4TileTex;
Texture2D mine5TileTex;
Texture2D mine6TileTex;
Texture2D mine7TileTex;
Texture2D mine8TileTex;
Texture2D bombTileTex;
Texture2D bombRedTileTex;

Texture2D frame1;
Texture2D frame2;
Texture2D frame3;
Texture2D smilling;
Texture2D scoreNumbers[10];

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
    hiddenTileTex     = LoadTexture("resources/tileHidden.png"); 
    hiddenTileFlagTex = LoadTexture("resources/tileFlag.png"); 
    mine1TileTex      = LoadTexture("resources/tileNumbers1.png"); 
    mine2TileTex      = LoadTexture("resources/tileNumbers2.png"); 
    mine3TileTex      = LoadTexture("resources/tileNumbers3.png"); 
    mine4TileTex      = LoadTexture("resources/tileNumbers4.png"); 
    mine5TileTex      = LoadTexture("resources/tileNumbers5.png"); 
    mine6TileTex      = LoadTexture("resources/tileNumbers6.png"); 
    mine7TileTex      = LoadTexture("resources/tileNumbers7.png"); 
    mine8TileTex      = LoadTexture("resources/tileNumbers8.png"); 
    bombTileTex       = LoadTexture("resources/bombTile.png"); 
    bombRedTileTex    = LoadTexture("resources/bombRedTile.png"); 

    revealedTileTex   = LoadTexture("resources/tileRevealed.png");
    frame1            = LoadTexture("resources/frame1.png");
    frame2            = LoadTexture("resources/frame2.png");
    frame3            = LoadTexture("resources/frame3.png");
    smilling          = LoadTexture("resources/btn_smiling.png");

    scoreNumbers[0]   = LoadTexture("resources/ScoreNumbers1.png"); 
    scoreNumbers[1]   = LoadTexture("resources/ScoreNumbers2.png"); 
    scoreNumbers[2]   = LoadTexture("resources/ScoreNumbers3.png"); 
    scoreNumbers[3]   = LoadTexture("resources/ScoreNumbers4.png"); 
    scoreNumbers[4]   = LoadTexture("resources/ScoreNumbers5.png"); 
    scoreNumbers[5]   = LoadTexture("resources/ScoreNumbers6.png"); 
    scoreNumbers[6]   = LoadTexture("resources/ScoreNumbers7.png"); 
    scoreNumbers[7]   = LoadTexture("resources/ScoreNumbers8.png"); 
    scoreNumbers[8]   = LoadTexture("resources/ScoreNumbers9.png"); 
    scoreNumbers[9]   = LoadTexture("resources/ScoreNumbers10.png"); 
}