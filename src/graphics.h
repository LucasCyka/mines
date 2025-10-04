#ifndef GRAPHICS
#define GRAPHICS

#include <raylib.h>
#include <stdio.h>
#include <string.h>

//textures
//TODO: move tiles textures into an array
extern Texture2D hiddenTileTex;
extern Texture2D hiddenTileFlagTex;
extern Texture2D mine1TileTex;
extern Texture2D mine2TileTex;
extern Texture2D mine3TileTex;
extern Texture2D mine4TileTex;
extern Texture2D mine5TileTex;
extern Texture2D mine6TileTex;
extern Texture2D mine7TileTex;
extern Texture2D mine8TileTex;
extern Texture2D bombTileTex;
extern Texture2D bombRedTileTex;
extern Texture2D revealedTileTex;

extern Texture2D frame1;
extern Texture2D frame2;
extern Texture2D frame3;
extern Texture2D smilling;
extern Texture2D angry;
extern Texture2D sunglasses;
extern Texture2D smillingPressed;
extern Texture2D angryPressed;
extern Texture2D sunglassesPressed;
extern Texture2D scoreNumbers[10];

void LoadTextures();

#endif