#include "graphics.h"

//textures
Texture2D hiddenTileTex;
Texture2D revealedTileTex;
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
    hiddenTileTex   = LoadTexture("resources/tileHidden.png"); 
    revealedTileTex = LoadTexture("resources/tileRevealed.png");
    frame1          = LoadTexture("resources/frame1.png");
    frame2          = LoadTexture("resources/frame2.png");
    frame3          = LoadTexture("resources/frame3.png");
    smilling        = LoadTexture("resources/btn_smiling.png");

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