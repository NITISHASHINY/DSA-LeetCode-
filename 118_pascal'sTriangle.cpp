class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;   // final Pascal's triangle

        for (int r = 0; r < numRows; r++) {
            vector<int> row(r + 1, 1);   // row of length r+1, all values 1

            for (int c = 1; c < r; c++) {   // fill middle values
                row[c] = result[r - 1][c - 1] + result[r - 1][c];
            }

            result.push_back(row);   // store this row
        }

        return result;
    }
};
