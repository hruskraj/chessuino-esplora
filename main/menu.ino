/**
 * @file menu.ino
 * @brief Menu functions.
 */

 /**
  * @brief Initialize default menu.
  * 
  * Background of the menu is white. Menu consists of three options.
  * <table >
  * <tr> <th>Option</th> </tr>
  * <tr> <td>New game</td> </tr>
  * <tr> <td>Controls</td> </tr>
  * <tr> <td>About</td> </tr>
  * </table>
  */
void menu1Init(){
  EsploraTFT.background(255,255,255);
  EsploraTFT.stroke(0,0,0);
  EsploraTFT.text("NEW GAME", 50, 60);
  EsploraTFT.text("CONTROLS", 50, 80);
  EsploraTFT.text("ABOUT", 50, 100);
  //selector
  EsploraTFT.text(">", 30, 60);
}
/**
 * @brief Moves menu selector.
 * 
 * @param to selected option
 * @sa states
 */
void menu1MoveSelector(enum states to){
  EsploraTFT.noStroke();
  EsploraTFT.fill(255,255,255);
  EsploraTFT.rect(30, 60, 20, 60);
  EsploraTFT.stroke(0,0,0);

  if(to == MENU_NEW_GAME)
    EsploraTFT.text(">", 30, 60);
  else if(to == MENU_CONTROLS)
    EsploraTFT.text(">", 30, 80);
  else
    EsploraTFT.text(">", 30, 100);
}
 /**
  * @brief Initialize opponent selection menu.
  * 
  * Background of the menu is white. Menu consists of three options.
  * <table >
  * <tr> <th>Option</th> </tr>
  * <tr> <td>VS player</td> </tr>
  * <tr> <td>VS easy AI</td> </tr>
  * <tr> <td>VS hard AI</td> </tr>
  * </table>
  */
void menu2Init(){
  EsploraTFT.background(255,255,255);
  EsploraTFT.stroke(0,0,0);
  EsploraTFT.text("VS PLAYER", 50, 60);
  EsploraTFT.text("VS EASY AI", 50, 80);
  EsploraTFT.text("VS HARD AI", 50, 100);
  EsploraTFT.text(">", 30, 60);
}
/**
 * @brief Moves menu selector.
 * 
 * @param to selected option
 * @sa states
 */
void menu2MoveSelector(enum states to){
  EsploraTFT.noStroke();
  EsploraTFT.fill(255,255,255);
  EsploraTFT.rect(30, 60, 20, 60);
  EsploraTFT.stroke(0,0,0);

  if(to == MENU_VS_PLAYER)
    EsploraTFT.text(">", 30, 60);
  else if(to == MENU_VS_AI_EASY)
    EsploraTFT.text(">", 30, 80);
  else
    EsploraTFT.text(">", 30, 100);
}

