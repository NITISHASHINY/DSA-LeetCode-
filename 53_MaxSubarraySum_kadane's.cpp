class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_sum=nums[0];
        int max_sum=nums[0];
        int i;
        for(i=1;i<nums.size();i++){
             curr_sum=max(nums[i], curr_sum+nums[i]);
             max_sum=max(curr_sum,max_sum);
        }
        return max_sum;
        
    }
};