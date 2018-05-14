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
  EsploraTFT.text("Chess on Arduino Esplora.", 5, 40);
  EsploraTFT.text("Play against another", 5, 48);
  EsploraTFT.text("player or AI.", 5, 56);
  EsploraTFT.text("En passant is not allowed.", 5, 64);
  EsploraTFT.text("Pawn is promoted to queen.", 5, 72);
}

