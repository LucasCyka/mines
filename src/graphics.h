#ifndef GRAPHICS
#define GRAPHICS

#include <raylib.h>
#include <stdio.h>
#include <string.h>

//textures
extern Texture2D hiddenTileTex;
extern Texture2D revealedTileTex;
extern Texture2D frame1;
extern Texture2D frame2;
extern Texture2D frame3;
extern Texture2D smilling;
extern Texture2D scoreNumbers[10];

void LoadTextures();

#endif