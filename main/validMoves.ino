/**
 * @file validMoves.ino
 * @brief File containing functions which determine valid moves.
 */
/**
 * @brief General function which determines valid moves.
 * 
 * @param fromR current row
 * @param fromC current column
 * @param toR new row
 * @param toC new column
 * @param piece piece which is being moved
 * @param castlingHappened in/out parameter, true if castling happened
 * @return true if is valid move
 * @sa board
 */
bool isValidMove(byte fromR, byte fromC, byte toR, byte toC, byte piece, bool & castlingHappened){
  //if this move would result in check then this is not valid move
  if(checkCheck(fromR, fromC, toR, toC))
    return false;
  //if castling happened then this is valid move
  if(castlingHappened = checkCastling(fromR, fromC, toR, toC))
    return true;

  bool legal = isLegalMove(fromR, fromC, toR, toC, piece, whiteOnTurn);
  //promotion to queen
  if(piece == 5 && legal && toR == 7)
    board[fromR][fromC] -= 2;
  if(piece == 11 && legal && toR == 0)
    board[fromR][fromC] -= 2;
    
  return legal;
}
/**
 * @brief Function which determines legal moves.
 * 
 * @param fromR current row
 * @param fromC current column
 * @param toR new row
 * @param toC new column
 * @param piece piece which is being moved
 * @param playerWhite whose move it is
 * @return true if is legal move
 * @sa board, whiteOnTurn
 */
bool isLegalMove(byte fromR, byte fromC, byte toR, byte toC, byte piece, bool playerWhite){
  if(checkCheck(fromR, fromC, toR, toC))
    return false;
  if((playerWhite && board[toR][toC] >= 6 && board[toR][toC] < 12) || (!playerWhite && board[toR][toC] < 6))
    return false;
  switch(piece){
    case 0: case 6:
      return isValidMoveRook(fromR, fromC, toR, toC);
    case 1: case 7:
      return isValidMoveKnight(fromR, fromC, toR, toC);
    case 2: case 8:
      return isValidMoveBishop(fromR, fromC, toR, toC);
    case 3: case 9:
      return isValidMoveQueen(fromR, fromC, toR, toC);
    case 4: case 10:
      return isValidMoveKing(fromR, fromC, toR, toC);
    case 5:
      return isValidMoveBlackPawn(fromR, fromC, toR, toC);
    case 11:
      return isValidMoveWhitePawn(fromR, fromC, toR, toC);
  }
  return false;
}
/**
 * @brief Check if there are any moves left.
 * 
 * @return true if such a move exists
 * @return false if there aren't any moves left
 */
bool hasAnyMove(){
  for(byte r = 0; r < 8; ++r)
    for(byte c = 0; c < 8; ++c)
      if((whiteOnTurn && board[r][c] >= 6 && board[r][c] < 12) || (!whiteOnTurn && board[r][c] < 6))
        for(byte toR = 0; toR < 8; ++toR)
          for(byte toC = 0; toC < 8; ++toC)
            if(isLegalMove(r, c, toR, toC, board[r][c], whiteOnTurn))
              return true;
  return false;
}
/**
 * @brief Checks if this move is castling.
 * 
 * @param fromR current row
 * @param fromC current column
 * @param toR new row
 * @param toC new column
 * @return true if this is castling
 * @sa castlingVars
 */
bool checkCastling(byte fromR, byte fromC, byte toR, byte toC){
  //castling is not allowed during check
  if(checkCheck(board, whiteOnTurn))
    return false;
  //tests if king is selected and pieces didn't move
  if(!(board[fromR][fromC] == 10 && castlingVars[0] && (castlingVars[1] || castlingVars[2])) &&
     !(board[fromR][fromC] == 4 && castlingVars[3] && (castlingVars[4] || castlingVars[5])))
    return false;
    
  if(toC == 7 && ((whiteOnTurn && castlingVars[1]) || (!whiteOnTurn && castlingVars[4]))){
    //if there are any pieces between rook and king then castling is not allowed
    if(board[toR][5] != 255 || board[toR][6] != 255)
      return false;
    return true;
  }
  if(toC == 0 && ((whiteOnTurn && castlingVars[2]) || (!whiteOnTurn && castlingVars[5]))){
    if(board[toR][1] != 255 || board[toR][2] != 255 || board[toR][3] != 255)
      return false;
    return true;
  }
  return false;
}
/**
 * @brief Checks check of specific player.
 * 
 * @param b chess board
 * @param playerWhite player
 * @return true if check
 */
bool checkCheck(const byte b[8][8], bool playerWhite){
  byte kingR, kingC;
  //find position of king
  for(byte i = 0; i < 8; ++i)
    for(byte j = 0; j < 8; ++j)
      if((playerWhite && b[i][j] == 10) || (!playerWhite && b[i][j] == 4)){
        kingR = i;
        kingC = j;
        break;
      }

  for(byte r = 0; r < 8; ++r)
    for(byte c = 0; c < 8; ++c)
      if(((playerWhite && b[r][c] <= 5) ||
        (!playerWhite && b[r][c] > 5 && b[r][c] <= 11))
         && (isLegalMove(r, c, kingR, kingC, b[r][c], !playerWhite))){
        return true;
      }
  return false;
}
/**
 * @brief Check if this move would result in check.
 * 
 * @param fromR current row
 * @param fromC current column
 * @param toR new row
 * @param toC new column
 * @return true if it would result in check
 * @return false otherwise
 */
bool checkCheck(byte fromR, byte fromC, byte toR, byte toC){
  byte b[8][8];
  for(byte i = 0; i < 8; ++i)
    for(byte j = 0; j < 8; ++j)
      b[i][j] = board[i][j];
 
  b[toR][toC] = b[fromR][fromC];
  b[fromR][fromC] = 255;
  return checkCheck(b, whiteOnTurn);
}
/**
 * @brief Checks if this is valid move for rook.
 * 
 * Rooks can only move horizontally or vertically.
 * 
 * @param fromR current row
 * @param fromC current column
 * @param toR new row
 * @param toC new column
 * @return true if it is valid move
 * @return false otherwise
 */
bool isValidMoveRook(byte fromR, byte fromC, byte toR, byte toC){
  if(fromR == toR && fromC != toC){
    if(fromC < toC){
      for(byte i = fromC + 1; i < toC; ++i)
        if(board[fromR][i] != 255)
          return false;
      return true;
    }
    else{
      for(byte i = fromC - 1; i > toC; --i)
        if(board[fromR][i] != 255)
          return false;
      return true;
    }
  }
  else if(fromC == toC && fromR != toR){
    if(fromR < toR){
      for(byte i = fromR + 1; i < toR; ++i)
        if(board[i][fromC] != 255)
          return false;
      return true;
    }
    else{
      for(byte i = fromR - 1; i > toR; --i)
        if(board[i][fromC] != 255)
          return false;
      return true;
    }
  }
  else
    return false;
}
/**
 * @brief Checks if this is valid move for knight.
 * 
 * Knights can move in 'L'-shape.
 * 
 * @param fromR current row
 * @param fromC current column
 * @param toR new row
 * @param toC new column
 * @return true if it is valid move
 * @return false otherwise
 */
bool isValidMoveKnight(byte fromR, byte fromC, byte toR, byte toC){
  if(abs(fromC - toC) == 1 && abs(fromR - toR) == 2)
    return true;
  if(abs(fromC - toC) == 2 && abs(fromR - toR) == 1)
    return true;
  return false;
}
/**
 * @brief Checks if this is valid move for bishop.
 * 
 * Bishops can only move diagonally.
 * 
 * @param fromR current row
 * @param fromC current column
 * @param toR new row
 * @param toC new column
 * @return true if it is valid move
 * @return false otherwise
 */
bool isValidMoveBishop(byte fromR, byte fromC, byte toR, byte toC){
  for(byte diff = 1; diff < 8; ++diff){
    if(fromR + diff == toR && fromC + diff == toC)
      return true;
    if(fromR + diff >= 8 || fromC + diff >= 8 || board[fromR + diff][fromC + diff] != 255)
      break;
  }
  for(byte diff = 1; diff < 8; ++diff){
    if(fromR - diff == toR && fromC + diff == toC)
      return true;
    if(fromR - diff < 0 || fromC + diff >= 8 || board[fromR - diff][fromC + diff] != 255)
      break;
  }
  for(byte diff = 1; diff < 8; ++diff){
    if(fromR + diff == toR && fromC - diff == toC)
      return true;
    if(fromR + diff >= 8 || fromC - diff < 0 || board[fromR + diff][fromC - diff] != 255)
      break;
  }
  for(byte diff = 1; diff < 8; ++diff){
    if(fromR - diff == toR && fromC - diff == toC)
      return true;
    if(fromR - diff < 0 || fromC - diff < 0 || board[fromR - diff][fromC - diff] != 255)
      break;
  }
  return false;
}
/**
 * @brief Checks if this is valid move for king.
 * 
 * Kings can move to any adjacent tile.
 * 
 * @param fromR current row
 * @param fromC current column
 * @param toR new row
 * @param toC new column
 * @return true if it is valid move
 * @return false otherwise
 */
bool isValidMoveKing(byte fromR, byte fromC, byte toR, byte toC){
  if(abs(fromR - toR) <= 1 && abs(fromC - toC) <= 1)
    return true;
  return false;
}
/**
 * @brief Checks if this is valid move for queen.
 * 
 * Queens combine movements of bishop and rook.
 * 
 * @param fromR current row
 * @param fromC current column
 * @param toR new row
 * @param toC new column
 * @return true if it is valid move
 * @return false otherwise
 * @sa isValidMoveBishop, isValidMoveRook
 */
bool isValidMoveQueen(byte fromR, byte fromC, byte toR, byte toC){
  if(isValidMoveBishop(fromR, fromC, toR, toC) || isValidMoveRook(fromR, fromC, toR, toC))
    return true;
  return false;
}
/**
 * @brief Checks if this is valid move for white pawn.
 * 
 * Pawns can move one tile forward or two tiles forward on its first move. Pawns can
 * also move one tile diagonally in front of it, if there is an enemy.
 * 
 * @param fromR current row
 * @param fromC current column
 * @param toR new row
 * @param toC new column
 * @return true if it is valid move
 * @return false otherwise
 */
bool isValidMoveWhitePawn(byte fromR, byte fromC, byte toR, byte toC){
  if(board[toR][toC] < 6 && fromR - toR == 1 && abs(fromC - toC) == 1)
    return true;
  if(fromC != toC)
    return false;
  if(fromR == 6 && toR == 4 && board[5][fromC] == 255)
    return true;
  if(fromR - toR == 1)
    return true;
  return false;
}
/**
 * @brief Checks if this is valid move for black pawn.
 * 
 * Pawns can move one tile forward or two tiles forward on its first move. Pawns can
 * also move one tile diagonally in front of it, if there is an enemy.
 * 
 * @param fromR current row
 * @param fromC current column
 * @param toR new row
 * @param toC new column
 * @return true if it is valid move
 * @return false otherwise
 */
bool isValidMoveBlackPawn(byte fromR, byte fromC, byte toR, byte toC){
  if(board[toR][toC] < 12 && toR - fromR == 1 && abs(fromC - toC) == 1)
    return true;
  if(fromC != toC)
    return false;
  if(fromR == 1 && toR == 3 && board[2][fromC] == 255)
    return true;
  if(toR - fromR == 1)
    return true;
  return false;
}
