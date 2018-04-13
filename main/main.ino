/**
 * @file main.ino
 * @brief Main file which includes setup and loop.
 */

#include <Esplora.h>
#include <TFT.h>
#include <SPI.h>
#include "definitions.h"

void setup(){
  EsploraTFT.begin();
  EsploraTFT.background(0, 0, 0);
  drawBoard();
  drawEveryPiece();
}

void loop(){
  
}
