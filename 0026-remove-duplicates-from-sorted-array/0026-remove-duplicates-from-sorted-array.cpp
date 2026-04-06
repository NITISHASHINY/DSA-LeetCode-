class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n;
        int count = 0;
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        n = nums.size();
        return n;
        
        


    }
};