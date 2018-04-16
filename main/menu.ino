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
  EsploraTFT.setTextSize(2);
  EsploraTFT.text("NEW GAME", 32, 30);
  EsploraTFT.text("CONTROLS", 32, 60);
  EsploraTFT.text("ABOUT", 50, 90);
  //selector
  EsploraTFT.text(">", 15, 30);
  EsploraTFT.text("<", 132, 30);
}
/**
 * @brief Moves menu selector.
 * 
 * @param to selected option
 * @sa states
 */
void menu1MoveSelector(enum states to){
  EsploraTFT.noStroke();
  EsploraTFT.fill(255, 255, 255);
  EsploraTFT.rect(15, 30, 15, 45);
  EsploraTFT.rect(132, 30, 15, 45);
  EsploraTFT.rect(32, 90, 15, 15);
  EsploraTFT.rect(115, 90, 15, 15);
  EsploraTFT.stroke(0,0,0);

  if(to == MENU_NEW_GAME){
    EsploraTFT.text(">", 15, 30);
    EsploraTFT.text("<", 132, 30);
  }
  else if(to == MENU_CONTROLS){
    EsploraTFT.text(">", 15, 60);
    EsploraTFT.text("<", 132, 60);
  }
  else{
    EsploraTFT.text(">", 32, 90);
    EsploraTFT.text("<", 115, 90);
  }
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
  EsploraTFT.text("VS PLAYER", 27, 30);
  EsploraTFT.text("VS EASY AI", 22, 60);
  EsploraTFT.text("VS HARD AI", 22, 90);
  //selector
  EsploraTFT.text(">", 10, 30);
  EsploraTFT.text("<", 137, 30);
}
/**
 * @brief Moves menu selector.
 * 
 * @param to selected option
 * @sa states
 */
void menu2MoveSelector(enum states to){
  EsploraTFT.noStroke();
  EsploraTFT.fill(255, 255, 255);
  EsploraTFT.rect(10, 30, 15, 15);
  EsploraTFT.rect(137, 30, 15, 15);
  EsploraTFT.rect(7, 60, 12, 45);
  EsploraTFT.rect(142, 60, 12, 45);
  EsploraTFT.stroke(0,0,0);

  if(to == MENU_VS_PLAYER){
    EsploraTFT.text(">", 10, 30);
    EsploraTFT.text("<", 137, 30);
  }
  else if(to == MENU_VS_AI_EASY){
    EsploraTFT.text(">", 7, 60);
    EsploraTFT.text("<", 142, 60);
  }
  else{
    EsploraTFT.text(">", 7, 90);
    EsploraTFT.text("<", 142, 90);
  }
}

