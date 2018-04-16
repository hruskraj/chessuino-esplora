///TBA
byte tileSelectorR;
///TBA
byte tileSelectorC;
/**
 * TBA
 */
void gameInit(){
  EsploraTFT.background(0, 0, 0);
  drawBoard();
  drawEveryPiece();
  tileSelectorR = 4;
  tileSelectorC = 3;
  drawTileSelector(blueColor, tileSelectorR, tileSelectorC);
}
/**
 * TBA
 */
void gameUpdate(){
  byte tmpR = tileSelectorR;
  byte tmpC = tileSelectorC;
  if(joystickIs(joystickLeft))
    tileSelectorC = (8 + tileSelectorC - 1) % 8;
  if(joystickIs(joystickRight))
    ++tileSelectorC %= 8;
  if(joystickIs(joystickUp))
    tileSelectorR = (8 + tileSelectorR - 1) % 8;
  if(joystickIs(joystickDown))
    ++tileSelectorR %= 8;
  //to remove blinking
  if(tmpR != tileSelectorR || tmpC != tileSelectorC)
    moveTileSelector(tmpR, tmpC, tileSelectorR, tileSelectorC, blueColor);
}



