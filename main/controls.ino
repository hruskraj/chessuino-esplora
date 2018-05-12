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
  EsploraTFT.text("Movement in menu", 10, 10);
  EsploraTFT.text("Joystick - move", 10, 18);
  EsploraTFT.text("Switch 1 - select", 10, 26);
  EsploraTFT.text("Switch 4 - back", 10, 34);
  EsploraTFT.text("Movement in game", 10, 42);
  EsploraTFT.text("Joystick - move around chess board", 10, 50);
  EsploraTFT.text("Switch 1 - select piece + move piece", 10, 58);
  EsploraTFT.text("Switch 3 - back to menu", 10, 66);
  EsploraTFT.text("Switch 4 - remove selector", 10, 74);
}

