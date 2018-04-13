/**
 * @file chessPieces.ino
 * @brief File contaning functions related to chess pieces.
 */

/**
 * @brief Get value from chess pieces array.
 * 
 * Array is stored in program storage space, 
 * so special function is necessary to get value.
 * 
 * @param i piece you want to get
 * @param j position on y axis
 * @param k position on x axis
 * @return int representing value for RGB
 */
int getTableEntry(int i, int j, int k){
  return pgm_read_word(&chessPieces[i][j][k]);
}
/**
 * @brief Get color of specific tile.
 * 
 * @param i row
 * @param j column
 * @return TileColor color
 */
const TileColor & getTileColor(short i, short j){
  return (i + j) % 2 == 0 ? lightColor : darkColor;  
}
/**
 * @brief Draws chess piece at given location.
 * 
 * @param l row
 * @param k column
 * @param piece piece
 */
void drawPiece(int l, int k, int piece){
  for(int i = 0; i < 16; ++i){
    for(int j = 0; j < 16; ++j){
      int t = getTableEntry(piece, i, j);
      if(t == noColor)
        continue;   
      EsploraTFT.stroke(t, t, t);
      EsploraTFT.point(k * 16 + i, l * 16 + j);
    }
  }
}
/**
 * @brief Draws every chess piece on default location.
 */
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
/**
 * @brief Draws chessboard.
 * 
 * Chessboard size is 8x8 squares. Every square is 16 
 * pixels tall and 16 pixels wide. Total size of chessboard 
 * is 128x128 pixels. Upper left square coordinates are 
 * [0,0] and bottom right square coordinates are [7,7].
 */
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
