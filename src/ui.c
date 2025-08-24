#include "ui.h"
#include "graphics.h"

button buttons[BUTTONS_NUMBER];

void InitUI(int _tileWidth, int _gameWidth){
    //buttons
    button btn1;
    btn1.rec       = (Rectangle) { _gameWidth/2-_tileWidth, 4, smilling.width,smilling.height };
    btn1.texture   = smilling;
    btn1.isPressed = false;
    buttons[0] = btn1;
}

void DrawUI(int _hiddenMines, int _elapsedTime){
    //frames
    DrawTexture(frame1,0,0,WHITE);
    DrawTexture(frame2,0,0,WHITE);
    DrawTexture(frame3,0,0,WHITE);


    //buttons
    for (int i =0; i < BUTTONS_NUMBER; i++){
        button btn = buttons[i];

        DrawTexture(btn.texture,btn.rec.x,btn.rec.y,WHITE);
    }

    //number of mines counter
    //1s
    DrawTexture(scoreNumbers[_hiddenMines % 10],37,6,WHITE);
    //10s
    DrawTexture(scoreNumbers[(int) (_hiddenMines/10) % 10],29,6,WHITE);
    //100s
    DrawTexture(scoreNumbers[(int) (_hiddenMines/100) % 10],21,6,WHITE);

    //timer
    //1s
    DrawTexture(scoreNumbers[_elapsedTime % 10],386,6,WHITE);
    //10s
    DrawTexture(scoreNumbers[(int) (_elapsedTime/10) % 10],379,6,WHITE);
    //100s
    DrawTexture(scoreNumbers[(int) (_elapsedTime/100) % 10],371,6,WHITE);

}

void DrawMines(){

}

void DrawTimer(){

}

void DrawFrames(){

}

