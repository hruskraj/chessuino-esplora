/**
 * @file AI.ino
 * @brief File containing AI.
 */
/**
 * @brief Initialization of AI.
 * 
 * Enables AI.
 * @sa AIEnabled
 */
void AIInit(){
  AIEnabled = true;
}
/**
 * @brief Makes any possible move.
 * 
 * Function goes through every possible move and stops when it finds any legal move.
 * 
 * @param from coordinates of selected piece
 * @param to coordinates of new location
 * @sa tileSelector, tileSelected, isLegalMove
 */
void AIMakeAnyMove(Coord & from, Coord & to){
  for(byte r = 0; r < 8; ++r)
    for(byte c = 0; c < 8; ++c)
      if(board[r][c] < 6){
        for(byte toR = 0; toR < 8; ++toR)
          for(byte toC = 0; toC < 8; ++toC)
            if(isLegalMove(r, c, toR, toC, board[r][c], whiteOnTurn)){
              from = Coord(r, c);
              to = Coord(toR, toC);
              return;
            }
      }
}
/**
 * @brief Makes random move.
 * 
 * When there was no legal move in the previous 500 random possibilities then legal
 * move is searched in all possibilities.
 * 
 * @param from coordinates of selected piece
 * @param to coordinates of new location
 * @sa tileSelector, tileSelected, isLegalMove
 */
void AIMakeTurn(Coord & from, Coord & to){
  byte a = random(0, 8);
  byte b = random(0, 8);
  byte c = random(0, 8);
  byte d = random(0, 8);
  int counter = 0;
  while(!isLegalMove(a, b, c, d, board[a][b], whiteOnTurn) && counter <= 500){
    a = random(0, 8);
    b = random(0, 8);
    c = random(0, 8);
    d = random(0, 8);
    ++counter;
  }
  if(counter > 500){
    AIMakeAnyMove(from, to);
    return;
  }
  from = Coord(a, b);
  to = Coord(c, d);
}
