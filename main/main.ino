/**
 * @file main.ino
 * @brief Main file which includes setup and loop.
 */

#include <Esplora.h>
#include <TFT.h>
#include <SPI.h>
#include "definitions.h"

enum states STATE, NEXT_STATE;

void setup(){
  EsploraTFT.begin();
  EsploraTFT.background(0, 0, 0);
  drawBoard();
  drawEveryPiece();
}

void loop(){
  switch(STATE){
    case MENU_1:
      break;
    case MENU_2:
      break;
    case GAME:
      break;
  }
  STATE = NEXT_STATE;
}
