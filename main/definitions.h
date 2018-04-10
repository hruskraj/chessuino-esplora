struct TileColor{
  byte r, g, b;
  TileColor(byte r, byte g, byte b) : r(r), g(g), b(b){};
};

const TileColor lightColor(255, 220, 145);
const TileColor darkColor(224, 155, 6);
 
/*   0 - black rook
 *   1 - black knight
 *   2 - black bishop
 *   3 - black queen
 *   4 - black king
 *   5 - black pawn
 *   6 - white rook
 *   7 - white knight
 *   8 - white bishop
 *   9 - white queen
 *  10 - white king
 *  11 - white pawn
 */
const PROGMEM int chessPieces[12][16][16] = {{{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 116, 22, -1, -1}, {-1, -1, -1, 22, 53, 63, -1, -1, -1, -1, 132, 64, 83, 17, -1, -1}, {-1, -1, -1, 54, 53, 111, 17, 0, 0, 0, 93, 110, 92, 17, -1, -1}, {-1, -1, -1, 133, 53, 111, 17, 0, 0, 0, 94, 110, 92, 17, -1, -1}, {-1, -1, -1, 23, 53, 111, 17, 0, 0, 0, 94, 110, 92, 17, -1, -1}, {-1, -1, -1, 23, 53, 111, 17, 0, 0, 0, 94, 110, 92, 17, -1, -1}, {-1, -1, -1, 133, 53, 111, 17, 0, 0, 0, 94, 110, 92, 17, -1, -1}, {-1, -1, -1, 54, 53, 111, 17, 0, 0, 0, 93, 110, 92, 17, -1, -1}, {-1, -1, -1, 22, 53, 63, -1, -1, -1, -1, 132, 62, 83, 17, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 116, 22, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}}, 
{{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, 123, 49, 40, 73, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, 153, 42, 2, 40, 63, 27, -1, -1, -1, -1, -1}, {-1, -1, -1, 135, 63, 88, 15, 0, 0, 0, 19, -1, -1, -1, -1, -1}, {-1, -1, -1, 19, 23, 175, 10, 0, 0, 31, -1, -1, 77, 38, -1, -1}, {-1, -1, -1, 40, 0, 0, 0, 0, 20, 165, -1, 42, 0, 20, -1, -1}, {-1, -1, 83, 19, 2, 0, 0, 14, 105, 142, 36, 0, 0, 20, -1, -1}, {-1, -1, -1, 92, 29, 11, 8, 16, 25, 4, 0, 0, 0, 20, -1, -1}, {-1, -1, -1, 164, 150, 0, 0, 0, 0, 0, 0, 0, 0, 20, -1, -1}, {-1, -1, -1, -1, 169, 76, 0, 0, 0, 0, 0, 0, 0, 20, -1, -1}, {-1, -1, -1, -1, -1, 175, 145, 30, 0, 0, 0, 0, 0, 20, -1, -1}, {-1, -1, -1, -1, -1, -1, 122, 178, 191, 156, 131, 114, 115, 129, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, 163, 116, 120, 128, 126, 121, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}}, 
{{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 27, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 98, 38, -1, -1}, {-1, -1, -1, -1, -1, -1, 184, 148, -1, -1, -1, -1, 79, 54, -1, -1}, {-1, -1, -1, -1, -1, 53, 8, 0, 31, 102, 139, 63, 77, 49, -1, -1}, {-1, -1, -1, -1, 55, 0, 12, 0, 0, 133, 136, 21, 56, 56, -1, -1}, {-1, -1, 29, 35, 9, 46, 167, 32, 0, 136, 136, 4, 26, 67, -1, -1}, {-1, -1, 29, 35, 9, 46, 167, 32, 0, 136, 136, 4, 26, 67, -1, -1}, {-1, -1, -1, -1, 55, 0, 12, 0, 0, 133, 136, 21, 56, 56, -1, -1}, {-1, -1, -1, -1, -1, 53, 8, 0, 31, 102, 139, 63, 77, 49, -1, -1}, {-1, -1, -1, -1, -1, -1, 184, 148, -1, -1, -1, -1, 79, 54, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 98, 38, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 27, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}}, 
{{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, 156, 63, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, 111, 6, 34, 70, 126, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, 60, 7, 8, 11, -1, -1, 130, 135, -1, -1}, {-1, -1, 112, 28, -1, -1, -1, 79, 16, 36, 123, 114, 141, 148, -1, -1}, {-1, -1, 121, 36, 70, 15, 6, 1, 3, 95, 58, 119, 140, 128, 153, -1}, {-1, -1, -1, -1, -1, -1, 144, 48, 10, 132, 20, 119, 125, 96, 136, -1}, {-1, -1, 40, 86, 109, 69, 45, 25, 8, 135, 17, 119, 105, 89, 145, -1}, {-1, -1, 40, 86, 109, 69, 45, 25, 8, 135, 17, 119, 105, 89, 145, -1}, {-1, -1, -1, -1, -1, -1, 144, 48, 10, 132, 20, 119, 125, 96, 136, -1}, {-1, -1, 121, 36, 70, 15, 6, 1, 3, 95, 58, 119, 140, 128, 153, -1}, {-1, -1, 113, 28, -1, -1, -1, 79, 16, 36, 123, 114, 141, 148, -1, -1}, {-1, -1, -1, -1, -1, -1, 60, 7, 8, 11, -1, -1, 130, 135, -1, -1}, {-1, -1, -1, 111, 6, 34, 70, 126, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, 156, 63, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}}, 
{{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, 138, 149, 157, 144, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, 132, 122, 0, 0, 137, 147, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, 114, 92, 0, 0, 6, 167, 133, 94, 125, -1, -1}, {-1, -1, -1, -1, -1, 156, 142, 0, 0, 27, 115, 142, 137, 36, -1, -1}, {-1, -1, -1, -1, -1, 134, 127, 63, 0, 69, 74, 129, 136, 11, -1, -1}, {-1, -1, 113, 163, 48, 0, 6, 129, 111, 121, 72, 106, 135, 0, -1, -1}, {-1, -1, 113, 163, 48, 0, 6, 129, 111, 121, 72, 106, 135, 0, -1, -1}, {-1, -1, -1, -1, -1, 134, 127, 63, 0, 69, 74, 129, 136, 11, -1, -1}, {-1, -1, -1, -1, -1, 156, 142, 0, 0, 27, 115, 142, 137, 36, -1, -1}, {-1, -1, -1, -1, -1, 114, 92, 0, 0, 6, 167, 133, 94, 125, -1, -1}, {-1, -1, -1, -1, -1, 132, 122, 0, 0, 137, 147, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, 138, 149, 157, 144, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}}, 
{{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 36, 1, 19, -1, -1}, {-1, -1, -1, -1, -1, -1, 98, 67, -1, 101, 9, 0, 0, 0, -1, -1}, {-1, -1, -1, -1, 53, 38, 1, 0, 3, 14, 0, 0, 0, 0, -1, -1}, {-1, -1, -1, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1}, {-1, -1, -1, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1}, {-1, -1, -1, -1, 53, 38, 1, 0, 3, 14, 0, 0, 0, 0, -1, -1}, {-1, -1, -1, -1, -1, -1, 98, 67, -1, 101, 9, 0, 0, 0, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 36, 1, 19, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}}, 
{{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, 166, 139, -1, -1, -1, -1, -1, -1, -1, 138, 73, -1, -1}, {-1, -1, -1, 112, 147, 73, 169, 181, 181, 181, 141, 57, 54, 129, -1, -1}, {-1, -1, -1, 80, 157, 149, 193, 193, 193, 193, 164, 81, 123, 127, -1, -1}, {-1, -1, -1, 146, 150, 150, 251, 255, 255, 255, 191, 81, 123, 127, -1, -1}, {-1, -1, -1, 85, 178, 150, 251, 255, 255, 255, 191, 81, 123, 127, -1, -1}, {-1, -1, -1, 85, 178, 150, 251, 255, 255, 255, 191, 81, 123, 127, -1, -1}, {-1, -1, -1, 146, 150, -1, 251, 255, 255, 255, 191, 81, 123, 127, -1, -1}, {-1, -1, -1, 80, 157, 149, 193, 193, 193, 193, 164, 81, 123, 127, -1, -1}, {-1, -1, -1, 112, 147, 73, 169, 181, 181, 181, 141, 57, 54, 129, -1, -1}, {-1, -1, -1, 166, 139, -1, -1, -1, -1, -1, -1, -1, 138, 73, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}}, 
{{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, 145, 109, 131, 115, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, 167, 107, 212, 215, 175, 62, -1, -1, -1, -1, -1}, {-1, -1, -1, 154, 105, 125, 240, 255, 255, 240, 71, -1, -1, -1, -1, -1}, {-1, -1, -1, 110, 227, 80, 245, 255, 255, 122, -1, -1, 117, 81, -1, -1}, {-1, -1, -1, 102, 255, 255, 255, 255, 158, 179, -1, 102, 242, 153, -1, -1}, {-1, -1, 108, 147, 255, 255, 255, 176, 132, 159, 114, 246, 255, 153, -1, -1}, {-1, -1, -1, 113, 255, 255, 118, 92, 142, 204, 255, 255, 255, 153, -1, -1}, {-1, -1, -1, 167, 198, 255, 255, 255, 255, 255, 255, 255, 255, 153, -1, -1}, {-1, -1, -1, -1, 102, 253, 255, 255, 255, 255, 255, 255, 255, 153, -1, -1}, {-1, -1, -1, -1, -1, 112, 245, 255, 255, 255, 255, 255, 255, 153, -1, -1}, {-1, -1, -1, -1, -1, -1, 116, 130, 198, 249, 255, 255, 255, 153, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, 173, 124, 119, 119, 119, 95, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}}, 
{{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 52, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 128, 109, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, 163, -1, -1, -1, -1, 119, 119, -1, -1}, {-1, -1, -1, -1, -1, 101, 180, 209, 114, 122, 63, 105, 119, 121, -1, -1}, {-1, -1, -1, -1, 101, 242, 243, 255, 249, 92, 119, 151, 102, 121, -1, -1}, {-1, -1, 107, 85, 186, 209, 88, 223, 255, 119, 119, 184, 93, 119, -1, -1}, {-1, -1, 107, 85, 186, 209, 88, 223, 255, 119, 119, 184, 93, 119, -1, -1}, {-1, -1, -1, -1, 101, 242, 243, 255, 249, 92, 119, 151, 102, 121, -1, -1}, {-1, -1, -1, -1, -1, 101, 180, 209, 114, 122, 63, 105, 119, 121, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, 163, -1, -1, -1, -1, 119, 119, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 128, 109, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 52, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}}, 
{{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, 171, 113, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, 136, 86, 79, 121, 163, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, 94, 150, 146, 45, 149, -1, 146, 133, -1, -1}, {-1, -1, 117, 98, -1, -1, 180, 78, 62, 163, 87, 76, 185, 125, -1, -1}, {-1, -1, 124, 104, 111, 55, 136, 193, 95, 198, 119, 127, 247, 147, -1, -1}, {-1, -1, -1, -1, -1, -1, 165, 88, 64, 211, 120, 119, 255, 164, -1, -1}, {-1, -1, 105, 123, 130, 116, 116, 141, 77, 221, 119, 119, 255, 170, -1, -1}, {-1, -1, 105, 123, 130, 116, 116, 141, 77, 221, 119, 119, 255, 170, -1, -1}, {-1, -1, -1, -1, -1, -1, 165, 88, 64, 211, 120, 119, 255, 164, -1, -1}, {-1, -1, 124, 104, 111, 55, 136, 193, 95, 198, 119, 127, 247, 147, -1, -1}, {-1, -1, 117, 98, -1, -1, 180, 78, 62, 163, 87, 76, 185, 125, -1, -1}, {-1, -1, -1, 136, -1, -1, 94, 150, 146, 45, 149, -1, 146, 133, -1, -1}, {-1, -1, -1, -1, 86, 79, 121, 163, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, 171, 113, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}}, 
{{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, 108, 146, 132, 134, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, 143, 220, 255, 255, 187, 131, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, 119, 255, 255, 255, 255, 84, 84, 113, 82, -1, -1}, {-1, -1, -1, -1, -1, 168, 195, 255, 255, 228, 140, 113, 118, 125, -1, -1}, {-1, -1, -1, -1, -1, 153, 84, 240, 255, 186, 183, 126, 119, 170, -1, -1}, {-1, -1, 113, 163, 98, 216, 175, 71, 170, 128, 188, 149, 120, 198, 176, -1}, {-1, -1, 113, 163, 98, 216, 175, 71, 170, 128, 188, 149, 120, 198, 176, -1}, {-1, -1, -1, -1, -1, 153, 84, 240, 255, 186, 183, 126, 119, 170, -1, -1}, {-1, -1, -1, -1, -1, 168, 195, 255, 255, 228, 140, 113, 118, 125, -1, -1}, {-1, -1, -1, -1, -1, 119, 255, 255, 255, 255, 84, 84, 113, 82, -1, -1}, {-1, -1, -1, -1, -1, 143, 220, 255, 255, 187, 131, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, 108, 146, 132, 134, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}}, 
{{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 123, 199, 186, -1, -1}, {-1, -1, -1, -1, -1, -1, 129, 119, -1, 129, 195, 255, 255, 255, -1, -1}, {-1, -1, -1, -1, 116, 83, 229, 255, 208, 136, 255, 255, 255, 255, -1, -1}, {-1, -1, -1, 119, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, -1, -1}, {-1, -1, -1, 119, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, -1, -1}, {-1, -1, -1, -1, 116, 83, 229, 255, 208, 136, 255, 255, 255, 255, -1, -1}, {-1, -1, -1, -1, -1, -1, 129, 119, -1, 129, 195, 255, 255, 255, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 123, 199, 186, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}}};

