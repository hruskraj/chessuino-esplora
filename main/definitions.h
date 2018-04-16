/**
 * @file definitions.h
 * @brief Definitions of constants.
 */

/**
 * @struct Color
 * @brief Simple structure representating color.
 * 
 * Every color is defined by RGB values.
 */
struct Color{
  ///red
  byte r;
  ///green 
  byte g;
  ///blue
  byte b;
  /**
   * @brief Constructor.
   * 
   * @param r red
   * @param g green
   * @param b blue
   */
  Color(byte r, byte g, byte b) : r(r), g(g), b(b){};
};

///Light color.
const Color lightColor = Color(255, 220, 145);
///Dark color.
const Color darkColor = Color(224, 155, 6);
///Blue color.
const Color blueColor = Color(0, 0, 255);

/**
 * States of the program.
 */
enum states{
  MENU_NEW_GAME, ///< Menu selection of new game
  MENU_CONTROLS, ///< Menu selection of controls
  MENU_ABOUT, ///< Menu selection of about
  MENU_VS_PLAYER, ///< Menu selection of vs player
  MENU_VS_AI_EASY, ///< Menu selection of vs easy AI
  MENU_VS_AI_HARD, ///< Menu selection of vs hard AI
  CONTROLS, ///< Controls
  ABOUT, ///< About
  GAME ///< Game
};

/**
 * @brief Array of chess pieces
 * 
 * Every chess piece is represented by RGB value. All three parts
 * of the RGB are the same. 202 is used to indicate that there is no color.
 * <table>
 *   <tr> <th>index</th> <th>piece</th> </tr>
 *   <tr> <td>0</td> <td>black rook</td> </tr>
 *   <tr> <td>1</td> <td>black knight</td> </tr>
 *   <tr> <td>2</td> <td>black bishop</td> </tr>
 *   <tr> <td>3</td> <td>black queen</td> </tr> 
 *   <tr> <td>4</td> <td>black king</td> </tr>
 *   <tr> <td>5</td> <td>black pawn</td> </tr>
 *   <tr> <td>6</td> <td>white rook</td> </tr>
 *   <tr> <td>7</td> <td>white knight</td> </tr>
 *   <tr> <td>8</td> <td>white bishop</td> </tr>
 *   <tr> <td>9</td> <td>white queen</td> </tr>
 *   <tr> <td>10</td> <td>white king</td> </tr>
 *   <tr> <td>11</td> <td>white pawn</td> </tr>
 * </table>
 */
const PROGMEM byte chessPieces[12][16][16] = {{{202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 116, 22, 202, 202}, {202, 202, 202, 22, 53, 63, 202, 202, 202, 202, 132, 64, 83, 17, 202, 202}, {202, 202, 202, 54, 53, 111, 17, 0, 0, 0, 93, 110, 92, 17, 202, 202}, {202, 202, 202, 133, 53, 111, 17, 0, 0, 0, 94, 110, 92, 17, 202, 202}, {202, 202, 202, 23, 53, 111, 17, 0, 0, 0, 94, 110, 92, 17, 202, 202}, {202, 202, 202, 23, 53, 111, 17, 0, 0, 0, 94, 110, 92, 17, 202, 202}, {202, 202, 202, 133, 53, 111, 17, 0, 0, 0, 94, 110, 92, 17, 202, 202}, {202, 202, 202, 54, 53, 111, 17, 0, 0, 0, 93, 110, 92, 17, 202, 202}, {202, 202, 202, 22, 53, 63, 202, 202, 202, 202, 132, 62, 83, 17, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 116, 22, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}}, 
{{202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 123, 49, 40, 73, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 153, 42, 2, 40, 63, 27, 202, 202, 202, 202, 202}, {202, 202, 202, 135, 63, 88, 15, 0, 0, 0, 19, 202, 202, 202, 202, 202}, {202, 202, 202, 19, 23, 175, 10, 0, 0, 31, 202, 202, 77, 38, 202, 202}, {202, 202, 202, 40, 0, 0, 0, 0, 20, 165, 202, 42, 0, 20, 202, 202}, {202, 202, 83, 19, 2, 0, 0, 14, 105, 142, 36, 0, 0, 20, 202, 202}, {202, 202, 202, 92, 29, 11, 8, 16, 25, 4, 0, 0, 0, 20, 202, 202}, {202, 202, 202, 164, 150, 0, 0, 0, 0, 0, 0, 0, 0, 20, 202, 202}, {202, 202, 202, 202, 169, 76, 0, 0, 0, 0, 0, 0, 0, 20, 202, 202}, {202, 202, 202, 202, 202, 175, 145, 30, 0, 0, 0, 0, 0, 20, 202, 202}, {202, 202, 202, 202, 202, 202, 122, 178, 191, 156, 131, 114, 115, 129, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 163, 116, 120, 128, 126, 121, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}}, 
{{202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 27, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 98, 38, 202, 202}, {202, 202, 202, 202, 202, 202, 184, 148, 202, 202, 202, 202, 79, 54, 202, 202}, {202, 202, 202, 202, 202, 53, 8, 0, 31, 102, 139, 63, 77, 49, 202, 202}, {202, 202, 202, 202, 55, 0, 12, 0, 0, 133, 136, 21, 56, 56, 202, 202}, {202, 202, 29, 35, 9, 46, 167, 32, 0, 136, 136, 4, 26, 67, 202, 202}, {202, 202, 29, 35, 9, 46, 167, 32, 0, 136, 136, 4, 26, 67, 202, 202}, {202, 202, 202, 202, 55, 0, 12, 0, 0, 133, 136, 21, 56, 56, 202, 202}, {202, 202, 202, 202, 202, 53, 8, 0, 31, 102, 139, 63, 77, 49, 202, 202}, {202, 202, 202, 202, 202, 202, 184, 148, 202, 202, 202, 202, 79, 54, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 98, 38, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 27, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}}, 
{{202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 156, 63, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 111, 6, 34, 70, 126, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 202, 60, 7, 8, 11, 202, 202, 130, 135, 202, 202}, {202, 202, 112, 28, 202, 202, 202, 79, 16, 36, 123, 114, 141, 148, 202, 202}, {202, 202, 121, 36, 70, 15, 6, 1, 3, 95, 58, 119, 140, 128, 153, 202}, {202, 202, 202, 202, 202, 202, 144, 48, 10, 132, 20, 119, 125, 96, 136, 202}, {202, 202, 40, 86, 109, 69, 45, 25, 8, 135, 17, 119, 105, 89, 145, 202}, {202, 202, 40, 86, 109, 69, 45, 25, 8, 135, 17, 119, 105, 89, 145, 202}, {202, 202, 202, 202, 202, 202, 144, 48, 10, 132, 20, 119, 125, 96, 136, 202}, {202, 202, 121, 36, 70, 15, 6, 1, 3, 95, 58, 119, 140, 128, 153, 202}, {202, 202, 113, 28, 202, 202, 202, 79, 16, 36, 123, 114, 141, 148, 202, 202}, {202, 202, 202, 202, 202, 202, 60, 7, 8, 11, 202, 202, 130, 135, 202, 202}, {202, 202, 202, 111, 6, 34, 70, 126, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 156, 63, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}}, 
{{202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 202, 138, 149, 157, 144, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 132, 122, 0, 0, 137, 147, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 114, 92, 0, 0, 6, 167, 133, 94, 125, 202, 202}, {202, 202, 202, 202, 202, 156, 142, 0, 0, 27, 115, 142, 137, 36, 202, 202}, {202, 202, 202, 202, 202, 134, 127, 63, 0, 69, 74, 129, 136, 11, 202, 202}, {202, 202, 113, 163, 48, 0, 6, 129, 111, 121, 72, 106, 135, 0, 202, 202}, {202, 202, 113, 163, 48, 0, 6, 129, 111, 121, 72, 106, 135, 0, 202, 202}, {202, 202, 202, 202, 202, 134, 127, 63, 0, 69, 74, 129, 136, 11, 202, 202}, {202, 202, 202, 202, 202, 156, 142, 0, 0, 27, 115, 142, 137, 36, 202, 202}, {202, 202, 202, 202, 202, 114, 92, 0, 0, 6, 167, 133, 94, 125, 202, 202}, {202, 202, 202, 202, 202, 132, 122, 0, 0, 137, 147, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 202, 138, 149, 157, 144, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}}, 
{{202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 36, 1, 19, 202, 202}, {202, 202, 202, 202, 202, 202, 98, 67, 202, 101, 9, 0, 0, 0, 202, 202}, {202, 202, 202, 202, 53, 38, 1, 0, 3, 14, 0, 0, 0, 0, 202, 202}, {202, 202, 202, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 202, 202}, {202, 202, 202, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 202, 202}, {202, 202, 202, 202, 53, 38, 1, 0, 3, 14, 0, 0, 0, 0, 202, 202}, {202, 202, 202, 202, 202, 202, 98, 67, 202, 101, 9, 0, 0, 0, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 36, 1, 19, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}}, 
{{202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 166, 139, 202, 202, 202, 202, 202, 202, 202, 138, 73, 202, 202}, {202, 202, 202, 112, 147, 73, 169, 181, 181, 181, 141, 57, 54, 129, 202, 202}, {202, 202, 202, 80, 157, 149, 193, 193, 193, 193, 164, 81, 123, 127, 202, 202}, {202, 202, 202, 146, 150, 150, 251, 255, 255, 255, 191, 81, 123, 127, 202, 202}, {202, 202, 202, 85, 178, 150, 251, 255, 255, 255, 191, 81, 123, 127, 202, 202}, {202, 202, 202, 85, 178, 150, 251, 255, 255, 255, 191, 81, 123, 127, 202, 202}, {202, 202, 202, 146, 150, 202, 251, 255, 255, 255, 191, 81, 123, 127, 202, 202}, {202, 202, 202, 80, 157, 149, 193, 193, 193, 193, 164, 81, 123, 127, 202, 202}, {202, 202, 202, 112, 147, 73, 169, 181, 181, 181, 141, 57, 54, 129, 202, 202}, {202, 202, 202, 166, 139, 202, 202, 202, 202, 202, 202, 202, 138, 73, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}}, 
{{202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 145, 109, 131, 115, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 167, 107, 212, 215, 175, 62, 202, 202, 202, 202, 202}, {202, 202, 202, 154, 105, 125, 240, 255, 255, 240, 71, 202, 202, 202, 202, 202}, {202, 202, 202, 110, 227, 80, 245, 255, 255, 122, 202, 202, 117, 81, 202, 202}, {202, 202, 202, 102, 255, 255, 255, 255, 158, 179, 202, 102, 242, 153, 202, 202}, {202, 202, 108, 147, 255, 255, 255, 176, 132, 159, 114, 246, 255, 153, 202, 202}, {202, 202, 202, 113, 255, 255, 118, 92, 142, 204, 255, 255, 255, 153, 202, 202}, {202, 202, 202, 167, 198, 255, 255, 255, 255, 255, 255, 255, 255, 153, 202, 202}, {202, 202, 202, 202, 102, 253, 255, 255, 255, 255, 255, 255, 255, 153, 202, 202}, {202, 202, 202, 202, 202, 112, 245, 255, 255, 255, 255, 255, 255, 153, 202, 202}, {202, 202, 202, 202, 202, 202, 116, 130, 198, 249, 255, 255, 255, 153, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 173, 124, 119, 119, 119, 95, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}}, 
{{202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 52, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 128, 109, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 163, 202, 202, 202, 202, 119, 119, 202, 202}, {202, 202, 202, 202, 202, 101, 180, 209, 114, 122, 63, 105, 119, 121, 202, 202}, {202, 202, 202, 202, 101, 242, 243, 255, 249, 92, 119, 151, 102, 121, 202, 202}, {202, 202, 107, 85, 186, 209, 88, 223, 255, 119, 119, 184, 93, 119, 202, 202}, {202, 202, 107, 85, 186, 209, 88, 223, 255, 119, 119, 184, 93, 119, 202, 202}, {202, 202, 202, 202, 101, 242, 243, 255, 249, 92, 119, 151, 102, 121, 202, 202}, {202, 202, 202, 202, 202, 101, 180, 209, 114, 122, 63, 105, 119, 121, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 163, 202, 202, 202, 202, 119, 119, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 128, 109, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 52, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}}, 
{{202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 171, 113, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 136, 86, 79, 121, 163, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 202, 94, 150, 146, 45, 149, 202, 146, 133, 202, 202}, {202, 202, 117, 98, 202, 202, 180, 78, 62, 163, 87, 76, 185, 125, 202, 202}, {202, 202, 124, 104, 111, 55, 136, 193, 95, 198, 119, 127, 247, 147, 202, 202}, {202, 202, 202, 202, 202, 202, 165, 88, 64, 211, 120, 119, 255, 164, 202, 202}, {202, 202, 105, 123, 130, 116, 116, 141, 77, 221, 119, 119, 255, 170, 202, 202}, {202, 202, 105, 123, 130, 116, 116, 141, 77, 221, 119, 119, 255, 170, 202, 202}, {202, 202, 202, 202, 202, 202, 165, 88, 64, 211, 120, 119, 255, 164, 202, 202}, {202, 202, 124, 104, 111, 55, 136, 193, 95, 198, 119, 127, 247, 147, 202, 202}, {202, 202, 117, 98, 202, 202, 180, 78, 62, 163, 87, 76, 185, 125, 202, 202}, {202, 202, 202, 136, 202, 202, 94, 150, 146, 45, 149, 202, 146, 133, 202, 202}, {202, 202, 202, 202, 86, 79, 121, 163, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 171, 113, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}}, 
{{202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 202, 108, 146, 132, 134, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 143, 220, 255, 255, 187, 131, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 119, 255, 255, 255, 255, 84, 84, 113, 82, 202, 202}, {202, 202, 202, 202, 202, 168, 195, 255, 255, 228, 140, 113, 118, 125, 202, 202}, {202, 202, 202, 202, 202, 153, 84, 240, 255, 186, 183, 126, 119, 170, 202, 202}, {202, 202, 113, 163, 98, 216, 175, 71, 170, 128, 188, 149, 120, 198, 176, 202}, {202, 202, 113, 163, 98, 216, 175, 71, 170, 128, 188, 149, 120, 198, 176, 202}, {202, 202, 202, 202, 202, 153, 84, 240, 255, 186, 183, 126, 119, 170, 202, 202}, {202, 202, 202, 202, 202, 168, 195, 255, 255, 228, 140, 113, 118, 125, 202, 202}, {202, 202, 202, 202, 202, 119, 255, 255, 255, 255, 84, 84, 113, 82, 202, 202}, {202, 202, 202, 202, 202, 143, 220, 255, 255, 187, 131, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 202, 108, 146, 132, 134, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}}, 
{{202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 123, 199, 186, 202, 202}, {202, 202, 202, 202, 202, 202, 129, 119, 202, 129, 195, 255, 255, 255, 202, 202}, {202, 202, 202, 202, 116, 83, 229, 255, 208, 136, 255, 255, 255, 255, 202, 202}, {202, 202, 202, 119, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 202, 202}, {202, 202, 202, 119, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 202, 202}, {202, 202, 202, 202, 116, 83, 229, 255, 208, 136, 255, 255, 255, 255, 202, 202}, {202, 202, 202, 202, 202, 202, 129, 119, 202, 129, 195, 255, 255, 255, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 123, 199, 186, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}, {202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202, 202}}};

///Value for no color.
const byte noColor = 202;

int joystickRight = 0, ///< Absolute value of the position of the joystick on x axis
    joystickLeft = 0, ///< Absolute value of the position of the joystick on x axis
    joystickUp = 0, ///< Absolute value of the position of the joystick on y axis
    joystickDown = 0; ///< Absolute value of the position of the joystick on y axis

