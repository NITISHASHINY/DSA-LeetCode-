class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0];
        int minProd = nums[0];
        int ans = nums[0];

        for(int i = 1 ; i<nums.size() ; i++){
            int x = nums[i];
            int currMax = max({
                x,
                x * maxProd,
                x * minProd
            });
            int currMin = min({
                x,
                x * maxProd,
                x * minProd
            });
            maxProd = currMax;
            minProd = currMin;

            ans = max(ans, maxProd);
        }
        return ans;
        
    }
};