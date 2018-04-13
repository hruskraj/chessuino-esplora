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
 * @return byte representing value of RGB
 * @sa chessPieces
 */
byte getTableEntry(byte i, byte j, byte k){
  return pgm_read_word(&chessPieces[i][j][k]);
}
/**
 * @brief Get color of specific tile.
 * 
 * @param r row
 * @param c column
 * @return Color color
 */
const Color & getTileColor(int r, int c){
  return (r + c) % 2 == 0 ? lightColor : darkColor;  
}
/**
 * @brief Draws chess piece at given location.
 * 
 * @param r row
 * @param c column
 * @param p piece
 * @sa chessPieces
 */
void drawPiece(byte r, byte c, byte p){
  for(int i = 0; i < 16; ++i){
    for(int j = 0; j < 16; ++j){
      byte t = getTableEntry(p, i, j);
      if(t == noColor)
        continue;   
      EsploraTFT.stroke(t, t, t);
      EsploraTFT.point(c * 16 + i, r * 16 + j);
    }
  }
}
/**
 * @brief Draws every chess piece on default location.
 * @sa drawPiece
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
 * @brief Removes chess piece at given location.
 * 
 * @param r row
 * @param c column
 * @sa Color
 */
void removePiece(byte r, byte c){
  Color t = getTileColor(r, c);
  EsploraTFT.fill(t.r, t.g, t.b);
  EsploraTFT.noStroke();
  EsploraTFT.rect(c * 16, r * 16, 16, 16);
}
/**
 * @brief Moves given piece to new place.
 * 
 * @param r current row
 * @param c current column
 * @param new_r new row
 * @param new_c new column
 * @param p piece to be moved
 * @sa removePiece, drawPiece
 */
void movePiece(byte r, byte c, byte new_r, byte new_c, byte p){
  removePiece(r, c);
  drawPiece(new_r, new_c, p);
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
/**
 * @brief Draws selector of specific color on given location.
 * 
 * @param cl color of the selector
 * @param r row
 * @param c column
 * @sa Color
 */
void drawSelector(Color cl, byte r, byte c){
  EsploraTFT.stroke(cl.r, cl.g, cl.b);
  EsploraTFT.noFill();
  EsploraTFT.rect(c * 16, r * 16, 16, 16);
}
/**
 * @brief Removes selector from given location.
 * 
 * @param r row 
 * @param c column
 */
void removeSelector(byte r, byte c){
  Color t = getTileColor(r, c);
  //raws selector of the same color as tile
  drawSelector(t, r, c);
}
/**
 * @brief Moves selector to new place.
 * 
 * @param r current row
 * @param c current column
 * @param new_r new row
 * @param new_c new column
 * @param cl color of the selector
 * @sa Color
 */
void moveSelector(byte r, byte c, byte new_r, byte new_c, Color cl){
  removeSelector(r, c);
  drawSelector(cl, new_r, new_c);
}







