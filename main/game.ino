/**
 * @file game.ino
 * @brief File containing game controlling functions. 
 */
/**
 * @brief Coordinates of tile selector.
 * @sa Coord
 */
Coord tileSelector;
/**
 * @brief Coordinates of selected tile.
 * @sa Coord
 */
Coord tileSelected;
///Determines if any tile is selected.
bool tileIsSelected;
/**
 * @brief Initialization of game.
 * 
 * Fills board with pieces, draws board, draws pieces. Sets variables.
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
  for(byte i = 0; i < 6; ++i)
    castlingVars[i] = true;
}
/**
 * @brief Updates tile selector.
 * 
 * Checks joystick and moves tile selector accordingly. 
 * @sa joystickIs
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
  //draw only if coordinates changed to remove blinking
  if(tmp != tileSelector){
    moveTileSelector(tmp, tileSelector, blueColor);
    //if selector was on selected location then previous command would erase selector
    if(tileIsSelected)
      drawTileSelector(tileSelected, blueColor);
  }
}
/**
 * @brief Evaluate castling variables. 
 * 
 * @sa castlingVars
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
 * @brief Evaluate castling.
 */
void evaluateCastling(){
  if(tileSelector.c == 7){
    board[tileSelector.r][5] = board[tileSelector.r][7];
    board[tileSelector.r][6] = board[tileSelected.r][tileSelected.c];
    movePiece(tileSelector, Coord(tileSelector.r, 5), board[tileSelector.r][7]);
    movePiece(tileSelected, Coord(tileSelector.r, 6), board[tileSelector.r][4]);
  }
  else{
    board[tileSelector.r][3] = board[tileSelector.r][0];
    board[tileSelector.r][2] = board[tileSelected.r][tileSelected.c];
    movePiece(tileSelector, Coord(tileSelector.r, 3), board[tileSelector.r][0]);
    movePiece(tileSelected, Coord(tileSelector.r, 2), board[tileSelector.r][4]);
  }
  board[tileSelector.r][tileSelector.c] = 255;
  board[tileSelected.r][tileSelected.c] = 255;
}
/**
 * @brief Evaluate move.
 * 
 */
void evaluateMove(){
  if(tileIsSelected && tileSelected != tileSelector){
    bool castl = false;
    if(isValidMove(tileSelected.r, tileSelected.c, tileSelector.r, tileSelector.c, board[tileSelected.r][tileSelected.c], castl)){
      if(castl)
        evaluateCastling();
      else{
        removePiece(tileSelector);
        movePiece(tileSelected, tileSelector, board[tileSelected.r][tileSelected.c]);
        board[tileSelector.r][tileSelector.c] = board[tileSelected.r][tileSelected.c];
      }
      if(!AIEnabled){
        removeTileSelector(tileSelected);
        drawTileSelector(tileSelector, blueColor);
      }
      board[tileSelected.r][tileSelected.c] = 255;
      
      tileIsSelected = false;

      whiteOnTurn = !whiteOnTurn;
      evaluateCastlingVars(tileSelected.r, tileSelected.c);
      evaluateCastlingVars(tileSelector.r, tileSelector.c);
      if(!hasAnyMove()){
        NEXT_STATE = END;
        endInit();
        AIEnabled = false;
      }
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
 * @brief Game loop.
 */
void gameUpdate(){
  Coord tmp = tileSelector;
  if(AIEnabled && !whiteOnTurn){
    AIMakeTurn(tileSelected, tileSelector);
    tileIsSelected = true;
    evaluateMove();
    tileSelector = tmp;
  }
  updateSelector();
  if(buttonPressed(SWITCH_1))
    evaluateMove();
  if(buttonPressed(SWITCH_4) && !(AIEnabled && !whiteOnTurn)){
    if(tileSelected != tileSelector)
      removeTileSelector(tileSelected);
    tileIsSelected = false;
  }
}



