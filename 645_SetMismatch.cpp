class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;   // to store [duplicate, missing]
        vector<int> freq(n+1, 0);  // frequency array

        int slow = -1;   // duplicate number
        int a = -1;      // missing number

        // count frequency of each number
        for (int x : nums) {
            freq[x]++;
        }

        // find duplicate and missing using your vars
        for (int i = 1; i <= n; i++) {
            if (freq[i] == 2) slow = i;   // duplicate
            if (freq[i] == 0) a = i;      // missing
        }

        ans.push_back(slow);  // first value = duplicate
        ans.push_back(a);     // second value = missing
        return ans;
    }
};
