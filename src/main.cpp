#include <Arduino.h>
#include <SPI.h>
#include <SD.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <DFRobotDFPlayerMini.h>
#include "bmp_disp.h"
#include "playscreen.h"
#include "selectscreen.h"
#include "touch.h"

// TFT SD includes all the image files for
// icons and music thumbnails, the actual music is
// handled by a seperate sd that goes into DF Mini module
#define TFT_DC 9
#define TFT_CS 10
#define TFT_SDCS 6

// lcd screen and touch screen initialization, can set your own screen here
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

// Initialize music DFRobotDFPlayerMini music player
DFRobotDFPlayerMini music_player;

void setup(){
	init();

	// DF Mini communicates over serial1
	Serial.begin(9600);
	Serial1.begin(9600);

	// music player setup
	if (!music_player.begin(Serial1)) {  //Use softwareSerial to communicate with mp3.
		Serial.println("DFPlayer Fail");
	while(true) { };
	}

	Serial.println("DFPlayer online");
	music_player.volume(30);

	// must come before SD.begin() ...
	tft.begin();
	tft.setRotation(3);
	tft.fillScreen(0xFFFF);

	Serial.print("Initializing SD card...");

	// TFT SD initialization
	if (!SD.begin(TFT_SDCS)) {
		Serial.println("SD fail");
	while (true) { };
	} else {
		Serial.println("Initialized");
	}

}

int main(){
	setup();

  	enum State {SELECT_SCREEN, SELECT_TO_PLAY, PLAY, PLAY_TO_SELECT};
  	State state = SELECT_SCREEN;

  	SelectScreen ss = SelectScreen(&tft, music_player.readFileCounts()/2);

  	music_player.play(5);

  	while(true){
		if (state == SELECT_SCREEN){

		}
  	}

  	return 0;
}
