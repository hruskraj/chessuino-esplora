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
byte getTableEntry(byte i, byte j, byte k){
  return pgm_read_word(&chessPieces[i][j][k]);
}
/**
 * @brief Get color of specific tile.
 * 
 * @param r row
 * @param c column
 * @return TileColor color
 */
const TileColor & getTileColor(int r, int c){
  return (r + c) % 2 == 0 ? lightColor : darkColor;  
}
/**
 * @brief Draws chess piece at given location.
 * 
 * @param r row
 * @param c column
 * @param p piece
 */
void drawPiece(byte r, byte c, byte p){
  for(int i = 0; i < 16; ++i){
    for(int j = 0; j < 16; ++j){
      byte t = getTableEntry(p, i, j);
      if(t == noColor)
        continue;   
      EsploraTFT.stroke(t, t, t);
      EsploraTFT.point(r * 16 + i, c * 16 + j);
    }
  }
}
/**
 * @brief Draws every chess piece on default location.
 */
void drawEveryPiece(){
  for(byte k = 0; k < 2; ++k){
    for(byte i = 0; i < 3; ++i){
      drawPiece(0 + k * 7, i, i + k * 6);
      drawPiece(0 + k * 7, 7 - i, i + k * 6);
    }
    drawPiece(0 + k * 7, 3, 3 + k * 6);
    drawPiece(0 + k * 7, 4, 4 + k * 6);
    for(byte i = 0; i < 8; ++i)
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
  bool light = true;
  EsploraTFT.noStroke();
  for(int i = 0; i < 8; ++i){
    for(int j = 0; j < 8; ++j){
      if(light)
        EsploraTFT.fill(lightColor.r, lightColor.g, lightColor.b);
      else
        EsploraTFT.fill(darkColor.r, darkColor.g, darkColor.b);
      EsploraTFT.rect(i * 16, j * 16, 16, 16);
      light = !light;
    }
    light = !light;
  }
}
