/***
This class will handle all UI elements on the play screen. It will handle all the drawing and also have a 
function to handle touch input and change the UI elements accordingly.
***/
#include "Adafruit_GFX.h"    // Core graphics library
#include "Adafruit_ILI9341.h" // Hardware-specific library
#include "playscreen.h"
#define BLACK 0x0000
#define BLUE 0xADDAE6
#define RED 0xF800
#define CYAN 0x07FF
#define MAGENTA 0xF81F
#define WHITE 0xFFFF
#define LIGHTGREY 0xC638

#define WIDTH 320
#define HEIGHT 240

//play button data
//X Y and radius of the play button centered
#define PB_X 240
#define PB_Y 110 
#define PB_R 40

//height of the song progress bar
#define PBAR_H 15

//album image size
#define ALBUM_W 150
#define ALBUM_H 150
//Distance from the top and left edge of the screen to the album
#define ALBUM_PADDING_TOP 40
#define ALBUM_PADDING_LEFT 10

PlayScreen::PlayScreen(){

}
///this function takes in the x,y,value of the center of the button and the radius
//also takes in the state which is pressed or not pressed
void PlayScreen::drawPlay(int state,Adafruit_ILI9341 tft){
	//the button will be drawn differently depending on state(pressed or not pressed). NOT YET IMPLEMENTED
	//draw the play button
	tft.fillCircle(PB_X,PB_Y,PB_R,LIGHTGREY);
	tft.fillTriangle(PB_X-PB_R*0.4,PB_Y+PB_R*0.4,PB_X-PB_R*0.4,PB_Y-PB_R*0.4,PB_X+PB_R*0.4,PB_Y,WHITE);
}
void PlayScreen::drawProgressBar(int progress, Adafruit_ILI9341 tft){
	//draws the progress bar for the song. progress is a percentage i.e. a integer from 0 to 100
	tft.fillRect(0,HEIGHT-PBAR_H,WIDTH*progress/100,PBAR_H,RED);
}
void PlayScreen::drawAlbum(Adafruit_ILI9341 tft){
	//draws the album cover. currently just draw a square
	tft.fillRect(ALBUM_PADDING_LEFT,ALBUM_PADDING_TOP,ALBUM_W,ALBUM_H,BLACK);
}