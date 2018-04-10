int getTableEntry(int i, int j, int k){
  return pgm_read_word(&chessPieces[i][j][k]);
}
/*-------------------------------------------------------------*/
const TileColor & getTileColor(short i, short j){
  return (i + j) % 2 == 0 ? lightColor : darkColor;  
}
/*-------------------------------------------------------------*/
void drawPiece(int l, int k, int piece){
  for(int i = 0; i < 16; ++i){
    for(int j = 0; j < 16; ++j){
      int t = getTableEntry(piece, i, j);
      if(t == -1)
        continue;   
      EsploraTFT.stroke(t, t, t);
      EsploraTFT.point(k * 16 + i, l * 16 + j);
    }
  }
}
/*-------------------------------------------------------------*/
void drawEveryPiece(){
  for(int k = 0; k < 2; ++k){
    for(int i = 0; i < 3; ++i){
      drawPiece(0 + k * 7, i, i + k * 6);
      drawPiece(0 + k * 7, 7 - i, i + k * 6);
    }
    drawPiece(0 + k * 7, 3, 3 + k * 6);
    drawPiece(0 + k * 7, 4, 4 + k * 6);
    for(int i = 0; i < 8; ++i)
      drawPiece(1 + k * 5, i, 5 + k * 6);
  }
}
/*-------------------------------------------------------------*/
void drawBoard(){
  bool white = true;
  EsploraTFT.noStroke();
  for(int i = 0; i < 8; ++i){
    for(int j = 0; j < 8; ++j){
      if(white)
        EsploraTFT.fill(lightColor.r, lightColor.g, lightColor.b);
      else
        EsploraTFT.fill(darkColor.r, darkColor.g, darkColor.b);
      EsploraTFT.rect(i * 16, j * 16, 16, 16);
      white = !white;
    }
    white = !white;
  }
}
