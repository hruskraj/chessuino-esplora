///TBA
Coord tileSelector;
///TBA
Coord tileSelected;
///TBA
bool tileIsSelected;
/**
 * TBA
 */
void gameInit(){
  EsploraTFT.background(0, 0, 0);
  fillBoard();
  drawBoard();
  drawEveryPiece();
  tileSelector.r = tileSelected.r = 4;
  tileSelector.c = tileSelected.c = 3;
  tileIsSelected = false;
  whiteOnTurn = true;
  drawTileSelector(tileSelector, blueColor);
}
/**
 * TBA
 */
void updateSelector(){
  Coord tmp = tileSelector;
  if(joystickIs(joystickLeft))
    tileSelector.c = (8 + tileSelector.c - 1) % 8;
  if(joystickIs(joystickRight))
    ++tileSelector.c %= 8;
  if(joystickIs(joystickUp))
    tileSelector.r = (8 + tileSelector.r - 1) % 8;
  if(joystickIs(joystickDown))
    ++tileSelector.r %= 8;
  //Draw only if coordinates changed to remove blinking.
  if(tmp != tileSelector){
    moveTileSelector(tmp, tileSelector, blueColor);
    //If selector was on selected location then previous command would erase selector.
    drawTileSelector(tileSelector, blueColor);
  }
}
/**
 * TBA
 */
void evaluateMove(){
  if(tileIsSelected && tileSelected != tileSelector){
    if(isValidMove(tileSelected.r, tileSelected.c, tileSelector.r, tileSelector.c, board[tileSelected.r][tileSelected.c])){
      removeTileSelector(tileSelected);
      removePiece(tileSelector);
      drawTileSelector(tileSelector, blueColor);
      movePiece(tileSelected, tileSelector, board[tileSelected.r][tileSelected.c]);
      tileIsSelected = false;
      board[tileSelector.r][tileSelector.c] = board[tileSelected.r][tileSelected.c];
      board[tileSelected.r][tileSelected.c] = 255;
      whiteOnTurn = !whiteOnTurn;
    }
  }
  else{
    if((whiteOnTurn && board[tileSelector.r][tileSelector.c] <= 11 && board[tileSelector.r][tileSelector.c] >= 6) || 
       (!whiteOnTurn && board[tileSelector.r][tileSelector.c] <= 5)){    
      tileSelected = tileSelector;
      tileIsSelected = true;
      drawTileSelector(tileSelected, blueColor);
    }
  }
}
/**
 * TBA
 */
void gameUpdate(){
  updateSelector();
  if(buttonPressed(SWITCH_1))
    evaluateMove();
  if(buttonPressed(SWITCH_4)){
    if(tileSelected != tileSelector)
      removeTileSelector(tileSelected);
    tileIsSelected = false;
  }
}



