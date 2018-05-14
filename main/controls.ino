/**
 * @file controls.ino
 * @brief Information about contols.
 */
/**
 * @brief Writes information about controls.
 */
void controlsInit(){
  EsploraTFT.background(255,255,255);
  EsploraTFT.stroke(0,0,0);
  EsploraTFT.setTextSize(1);
  EsploraTFT.text("Movement in menu", 10, 15);
  EsploraTFT.text("Joystick - move", 10, 25);
  EsploraTFT.text("Switch 1 - select", 10, 33);
  EsploraTFT.text("Switch 4 - back", 10, 41);
  EsploraTFT.text("Movement in game", 10, 51);
  EsploraTFT.text("Joystick - move around", 10, 61);
  EsploraTFT.text("           chess board", 10, 69);
  EsploraTFT.text("Switch 1 - select piece", 10, 77);
  EsploraTFT.text("           + move piece", 10, 85);
  EsploraTFT.text("Switch 3 - back to menu", 10, 93);
  EsploraTFT.text("Switch 4 - remove", 10, 101);
  EsploraTFT.text("           selector", 10, 109);
}

