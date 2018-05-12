/**
 * TBA
 */
void AIInit(){
  AIEnabled = true;
}
/**
 * TBA
 */
void AIMakeAnyMove(Coord & from, Coord & to){
  for(byte r = 0; r < 8; ++r)
    for(byte c = 0; c < 8; ++c)
      if(board[r][c] < 6){
        for(byte toR = 0; toR < 8; ++toR)
          for(byte toC = 0; toC < 8; ++toC)
            if(isLegalMove(r, c, toR, toC, board[r][c])){
              from.r = r; from.c = c;
              to.r = toR; to.c = toC;
              return;
            }
      }
}
/**
 * TBA
 */
void AIMakeSimpleMove(Coord & from, Coord & to){
  byte a = random(0, 7);
  byte b = random(0, 7);
  byte c = random(0, 7);
  byte d = random(0, 7);
  int counter = 0;
  while(!isLegalMove(a, b, c, d, board[a][b]) && counter <= 500){
    a = random(0, 7);
    b = random(0, 7);
    c = random(0, 7);
    d = random(0, 7);
    ++counter;
  }
  if(counter > 500){
    AIMakeAnyMove(from, to);
    return;
  }
  from.r = a; from.c = b;
  to.r = b; to.c = d;
}
/**
 * TBA
 */
void AIMakeTurn(Coord & from, Coord & to){
  AIMakeSimpleMove(from, to);    
}


