/**
 * TBA
 */
void AIInit(bool difficulty){
  AIEnabled = true;
  AIDifficultyEasy = difficulty;
}
/**
 * TBA
 */
void AIMakeSimpleMove(Coord & from, Coord & to){
  byte a = random(0, 7);
  byte b = random(0, 7);
  byte c = random(0, 7);
  byte d = random(0, 7);
  while(!isLegalMove(a, b, c, d, board[a][b])){
    a = random(0, 7);
    b = random(0, 7);
    c = random(0, 7);
    d = random(0, 7);
  }
  from.r = a; from.c = b;
  to.r = b; to.c = d;
}
/**
 * TBA
 */
void AIMakeTurn(Coord & from, Coord & to){
  if(AIDifficultyEasy)
    AIMakeSimpleMove(from, to);
  else{
    AIMakeSimpleMove(from, to);
  }
    
}


