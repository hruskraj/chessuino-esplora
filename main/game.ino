///TBA
Coord tileSelector;
/**
 * TBA
 */
void gameInit(){
  EsploraTFT.background(0, 0, 0);
  drawBoard();
  drawEveryPiece();
  tileSelector.r = 4;
  tileSelector.c = 3;
  drawTileSelector(tileSelector, blueColor);
}
/**
 * TBA
 */
void gameUpdate(){
  Coord tmp = tileSelector;
  if(joystickIs(joystickLeft))
    tileSelector.c = (8 + tileSelector.c - 1) % 8;
  if(joystickIs(joystickRight))
    ++tileSelector.c %= 8;
  if(joystickIs(joystickUp))
    tileSelector.r = (8 + tileSelector.r - 1) % 8;
  if(joystickIs(joystickDown))
    ++tileSelector.r %= 8;
  //to remove blinking
  if(tmp != tileSelector)
    moveTileSelector(tmp, tileSelector, blueColor);
}



