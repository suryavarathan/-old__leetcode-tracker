// Last updated: 7/14/2026, 3:23:32 PM
class Solution {
    public boolean checkMove (char[][] board, int r, int c, char color) {
        board [r][c] = color;
        int n = board.length;
        int m = board[0].length;
        if (r <= 5) {
            int count = 1;
            for (int i = r+1; i < n; i++) {
                count++;
                if (board [i][c] == '.')
                    break;
                if (count < 3 && board [i][c] == color)
                    break;
                if (count >= 3 && board [i][c] == color) {
                    //System.out.println ("row down");
                    return true;
                }
            }
        }
        if (r >= 2) {
            int count = 1;
            for (int i = r-1; i >= 0; i--) {
                count++;
                if (board [i][c] == '.')
                    break;
                if (count < 3 && board [i][c] == color)
                    break;
                if (count >= 3 && board [i][c] == color) {
                    //System.out.println ("row up");
                    return true;
                }
            }
        }
        if (c >= 2) {
            int count = 1;
            for (int j = c-1; j >= 0; j--) {
                count++;
                if (board [r][j] == '.')
                    break;
                if (count < 3 && board [r][j] == color)
                    break;
                if (count >= 3 && board [r][j] == color) {
                    //System.out.println ("col left");
                    return true;
                }
            }
        }
        if (c <= 5) {
            int count = 1;
            for (int j = c+1; j < m; j++) {
                count++;
                if (board [r][j] == '.')
                    break;
                if (count < 3 && board [r][j] == color)
                    break;
                if (count >= 3 && board [r][j] == color) {
                    //System.out.println ("col right");
                    return true;
                }
            }
        }
        if (r >= 2 && c >= 2) {
            int count = 1;
            for (int i = r-1, j = c-1; i >= 0 && j >= 0; i--, j--) {
                count++;
                if (board [i][j] == '.')
                    break;
                if (count < 3 && board [i][j] == color)
                    break;
                if (count >= 3 && board [i][j] == color) {
                    //System.out.println ("dia left up");
                    return true;
                }
            }
        }
        if (r <= 5 && c <= 5) {
            int count = 1;
            for (int i = r+1, j = c+1; i < n && j < m; i++, j++) {
                count++;
                if (board [i][j] == '.')
                    break;
                if (count < 3 && board [i][j] == color)
                    break;
                if (count >= 3 && board [i][j] == color) {
                    //System.out.println ("dia right down");
                    return true;
                }
            }
        }
        if (r >= 2 && c <= 5) {
            int count = 1;
            for (int i = r-1, j = c+1; i >= 0 && j < m; i--, j++) {
                count++;
                if (board [i][j] == '.')
                    break;
                if (count < 3 && board [i][j] == color)
                    break;
                if (count >= 3 && board [i][j] == color) {
                    //System.out.println ("dia left down");
                    return true;
                }
            }
        }
        if (r <= 5 && c >= 2) {
            int count = 1;
            for (int i = r+1, j = c-1; i < n && j >= 0; i++, j--) {
                count++;
                if (board [i][j] == '.')
                    break;
                if (count < 3 && board [i][j] == color)
                    break;
                if (count >= 3 && board [i][j] == color) {
                    //System.out.println ("dia right up");
                    return true;
                }
            }
        }
        return false;
    }
}