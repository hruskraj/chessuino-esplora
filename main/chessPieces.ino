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
 * @return byte representing channel of RGB
 * @sa chessPieces
 */
byte getTableEntry(byte i, byte j, byte k){
  return pgm_read_word(&chessPieces[i][j][k]);
}
/**
 * @brief Get color of specific tile.
 * 
 * @param co coordinates of row and column
 * @return Color color
 * @sa Coord
 */
const Color & getTileColor(const Coord & co){
  return (co.r + co.c) % 2 == 0 ? lightColor : darkColor;  
}
/**
 * @brief Draws chess piece at given location.
 * 
 * @param co coordinates of location
 * @param p piece
 * @sa chessPieces, Coord
 */
void drawPiece(const Coord & co, byte p){
  for(int i = 0; i < 16; ++i)
    for(int j = 0; j < 16; ++j){
      byte t = getTableEntry(p, i, j);
      if(t == noColor)
        continue;   
      EsploraTFT.stroke(t, t, t);
      EsploraTFT.point(co.c * 16 + i, co.r * 16 + j);
    }
}
/**
 * @brief Fills chessboard with pieces at default location.
 * @sa board  
*/
void fillBoard(){
  for(byte i = 0; i < 8; ++i)
    for(byte j = 0; j < 8; ++j)
      board[i][j] = 255;
      
  for(byte k = 0; k < 2; ++k){
    for(byte i = 0; i < 3; ++i){
      board[0 + k * 7][i] = i + k * 6;
      board[0 + k * 7][7 - i] = i + k * 6;
    }
    board[0 + k * 7][3] = 3 + k * 6;
    board[0 + k * 7][4] = 4 + k * 6;
    for(byte i = 0; i < 8; ++i)
      board[1 + k * 5][i] = 5 + k * 6;
  }
}
/**
 * @brief Draws every chess piece on default location.
 * @sa drawPiece
 */
void drawEveryPiece(){
  for(byte i = 0; i < 8; ++i){
    for(byte j = 0; j < 8; ++j){
      if(board[i][j] == 255)
        continue;
      drawPiece(Coord(i, j), board[i][j]);  
    }
  }
}
/**
 * @brief Removes chess piece at given location.
 * 
 * @param co coordinates
 * @sa Color, Coord
 */
void removePiece(const Coord & co){
  Color t = getTileColor(co);
  EsploraTFT.fill(t.r, t.g, t.b);
  EsploraTFT.noStroke();
  EsploraTFT.rect(co.c * 16, co.r * 16, 16, 16);
}
/**
 * @brief Moves given piece to new place.
 * 
 * @param oldC coordinates of current position of chess piece
 * @param newC coordinates of new position
 * @param p piece to be moved
 * @sa removePiece, drawPiece, Coord
 */
void movePiece(const Coord & oldC, const Coord & newC, byte p){
  removePiece(oldC);
  drawPiece(newC, p);
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
 * @param co coordinates
 * @param cl color of the selector
 * @sa Color, Coord
 */
void drawTileSelector(const Coord & co, const Color & cl){
  EsploraTFT.stroke(cl.r, cl.g, cl.b);
  EsploraTFT.noFill();
  EsploraTFT.rect(co.c * 16, co.r * 16, 16, 16);
}
/**
 * @brief Removes selector from given location.
 * 
 * @param co coordinates
 * @sa Coord
 */
void removeTileSelector(const Coord & co){
  Color t = getTileColor(co);
  //draws selector of the same color as tile
  drawTileSelector(co, t);
}
/**
 * @brief Moves selector to new place.
 * 
 * @param oldC coordinates of current position
 * @param newC coordinates of new position
 * @param cl color of the selector
 * @sa Color, Coord
 */
void moveTileSelector(const Coord & oldC, const Coord & newC, Color cl){
  removeTileSelector(oldC);
  drawTileSelector(newC, cl);
}
