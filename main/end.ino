/**
 * @file end.ino
 * @brief Information about winner.
 */
void endInit(){
  EsploraTFT.background(255,255,255);
  EsploraTFT.stroke(0,0,0);
  EsploraTFT.setTextSize(3);
  if(whiteOnTurn)
    EsploraTFT.text("BLACK wins!", 10, 10);
  else
    EsploraTFT.text("WHITE wins!", 10, 10);
}

