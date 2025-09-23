#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (auto &row : matrix) {
            auto it = find(row.begin(), row.end(), target);
            if (it != row.end()) return true;  // found
        }
        return false;  // not found
    }
};
