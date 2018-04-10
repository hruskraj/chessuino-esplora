int getTableEntry(int i, int j, int k){
  return pgm_read_word(&chessPieces[i][j][k]);
}

const TileColor & getTileColor(short i, short j){
  return (i + j) % 2 == 0 ? lightColor : darkColor;  
}


