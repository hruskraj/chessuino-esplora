/**
 * @file end.ino
 * @brief Information about winner.
 */
/**
 * @brief Writes information about winner.
 */
void endInit(){
  EsploraTFT.background(255,255,255);
  EsploraTFT.stroke(0,0,0);
  EsploraTFT.setTextSize(3);
  if(whiteOnTurn)
    EsploraTFT.text("BLACK", 35, 30);
  else
    EsploraTFT.text("WHITE", 35, 30);
  EsploraTFT.text("wins!", 38, 60);
}

