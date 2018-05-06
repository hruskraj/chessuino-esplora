/**
 * @file validMoves.ino
 * @brief File containing functions which determine valid moves.
 */
/**
 * @brief General function of valid move.
 * 
 * @param fromR current row
 * @param fromC current column
 * @param toR new row
 * @param toC new column
 * @param piece piece which is being moved
 * @return true if is valid move
 * @sa board, whiteOnTurn
 */
bool isValidMove(byte fromR, byte fromC, byte toR, byte toC, byte piece){
  if(checkCheck(fromR, fromC, toR, toC))
    return false;
  if(checkCastling(fromR, fromC, toR, toC))
    return true;
  if((whiteOnTurn && board[toR][toC] >= 6 && board[toR][toC] < 12) || (!whiteOnTurn && board[toR][toC] < 6))
    return false;

  bool legal = isLegalMove(fromR, fromC, toR, toC, piece);
  //promotion to queen
  if(piece == 5 && legal && toR == 0)
    board[fromR][fromC] -= 2;
  if(piece == 11 && legal && toR == 7)
    board[fromR][fromC] -= 2;
    
  return legal;
}

bool isLegalMove(byte fromR, byte fromC, byte toR, byte toC, byte piece){
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
}

bool checkCastling(byte fromR, byte fromC, byte toR, byte toC){
  if(board[fromR][fromC] != 10 || board[toR][toC] != 6 || !castlingVars[0] ||
     board[fromR][fromC] != 4 || board[toR][toC] != 0 || !castlingVars[3] || 
     checkCheck(board, whiteOnTurn))
    return false;
  if(toC == 7 && ((whiteOnTurn && castlingVars[1]) || (!whiteOnTurn && castlingVars[4]))){
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

bool checkCheck(const byte b[8][8], bool playerWhite){
  byte kingR, kingC;
  for(byte i = 0; i < 8; ++i)
    for(byte j = 0; j < 8; ++j){
      if((playerWhite && b[i][j] == 10) || (!playerWhite && b[i][j] == 4)){
        kingR = i;
        kingC = j;
        break;
      }
    }

  for(byte r = 0; r < 8; ++r)
    for(byte c = 0; c < 8; ++c){
      if(((playerWhite && b[r][c] <= 5) ||
        (!playerWhite && b[r][c] > 5 && b[r][c] <= 11))
         && (isLegalMove(r, c, kingR, kingC, b[r][c])))
        return true;
    }
}

bool checkCheck(byte fromR, byte fromC, byte toR, byte toC){
  byte b[8][8];
  for(byte i = 0; i < 8; ++i)
    for(byte j = 0; j < 8; ++j)
      b[i][j] = board[i][j];
  b[toR][toC] = b[fromR][fromC];
  b[fromR][fromC] = 255;
  return checkCheck(b, whiteOnTurn);
}

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
bool isValidMoveKnight(byte fromR, byte fromC, byte toR, byte toC){
  if(abs(fromC - toC) == 1 && abs(fromR - toR) == 2)
    return true;
  if(abs(fromC - toC) == 2 && abs(fromR - toR) == 1)
    return true;
  return false;
}

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
bool isValidMoveKing(byte fromR, byte fromC, byte toR, byte toC){
  if(abs(fromR - toR) <= 1 && abs(fromC - toC) <= 1)
    return true;
  return false;
}
bool isValidMoveQueen(byte fromR, byte fromC, byte toR, byte toC){
  if(isValidMoveBishop(fromR, fromC, toR, toC) || isValidMoveRook(fromR, fromC, toR, toC))
    return true;
  return false;
}
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
