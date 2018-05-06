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
    drawTileSelector(tileSelected, blueColor);
  }
}
/**
 * 
 */
void evaluateCastlingVars(byte r, byte c){
  if(c == 7 && r == 7)
    castlingVars[1] = false;
  if(c == 4 && r == 7)
    castlingVars[0] = false;
  if(c == 0 && r == 7)
    castlingVars[2] = false;
  if(c == 7 && r == 0)
    castlingVars[4] = false;
  if(c == 4 && r == 0)
    castlingVars[3] = false;
  if(c == 0 && r == 0)
    castlingVars[5] = false;
}
/**
 * TBA
 */
void evaluateMove(){
  if(tileIsSelected && tileSelected != tileSelector){
    bool castl = false;
    if(isValidMove(tileSelected.r, tileSelected.c, tileSelector.r, tileSelector.c, board[tileSelected.r][tileSelected.c], castl)){
      if(castl){
        if(tileSelector.c == 7){
          board[tileSelector.r][5] = board[tileSelector.r][7];
          movePiece(tileSelector, Coord(tileSelector.r, 5), board[tileSelector.r][7]);
          movePiece(tileSelected, Coord(tileSelector.r, 6), board[tileSelector.r][4]);
        }
        else{
          board[tileSelector.r][3] = board[tileSelector.r][0];
          movePiece(tileSelector, Coord(tileSelector.r, 3), board[tileSelector.r][0]);
          movePiece(tileSelected, Coord(tileSelector.r, 2), board[tileSelector.r][4]);
        }
      }
      else{
        board[tileSelector.r][tileSelector.c] = board[tileSelected.r][tileSelected.c];
        movePiece(tileSelected, tileSelector, board[tileSelected.r][tileSelected.c]);
        removePiece(tileSelector);
      }
      removeTileSelector(tileSelected);
      board[tileSelected.r][tileSelected.c] = 255;
      drawTileSelector(tileSelector, blueColor);
      
      tileIsSelected = false;
      
      whiteOnTurn = !whiteOnTurn;
      evaluateCastlingVars(tileSelected.r, tileSelected.c);
      evaluateCastlingVars(tileSelector.r, tileSelector.c);
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



