/**
 * @file about.ino
 * @brief Information about the game.
 */
/**
 * @brief Writes information about game.
 */
void aboutInit(){
  EsploraTFT.background(255,255,255);
  EsploraTFT.stroke(0,0,0);
  EsploraTFT.setTextSize(1);
  EsploraTFT.text("Chess on Arduino Esplora.", 10, 10);
  EsploraTFT.text("Play against another player or AI.", 10, 18);
  EsploraTFT.text("En passant is not allowed.", 10, 26);
  EsploraTFT.text("Pawn is promoted to queen.", 10, 34);
}
