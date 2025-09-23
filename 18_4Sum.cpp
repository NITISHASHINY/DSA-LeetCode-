class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());  // sort to help skip duplicates

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicates for i

            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue; // skip duplicates for j

                for (int k = j + 1; k < n - 1; k++) {
                    for (int l = k + 1; l < n; l++) {
                        long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                        if (sum == target) {
                            result.push_back({nums[i], nums[j], nums[k], nums[l]});

                            // skip duplicates for k and l
                            while (l + 1 < n && nums[l] == nums[l + 1]) l++;
                            while (k + 1 < n && nums[k] == nums[k + 1]) k++;
                        }
                    }
                }
            }
        }
        return result;
    }
};