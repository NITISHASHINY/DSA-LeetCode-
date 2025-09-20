#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> s(nums.begin(), nums.end()); // O(n)
        int longest = 0;

        for (int num : s) {
            // only start when num is the first element in the sequence
            if (s.find(num - 1) == s.end()) {
                int currentNum = num;
                int streak = 1;

                while (s.find(currentNum + 1) != s.end()) {
                    currentNum++;
                    streak++;
                }
                longest = max(longest, streak);
            }
        }
        return longest;
    }
};
