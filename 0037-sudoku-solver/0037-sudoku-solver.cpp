class Solution {
public:
    // Check if placing 'c' is valid
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            // check row
            if (board[row][i] == c) return false;

            // check column
            if (board[i][col] == c) return false;

            // check 3x3 box
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
                return false;
        }
        return true;
    }

    // Backtracking function
    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {

                if (board[row][col] == '.') { // empty cell
                    for (char c = '1'; c <= '9'; c++) {

                        if (isValid(board, row, col, c)) {
                            board[row][col] = c;

                            if (solve(board)) return true;

                            // backtrack
                            board[row][col] = '.';
                        }
                    }
                    return false; // no valid number found
                }
            }
        }
        return true; // solved
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};