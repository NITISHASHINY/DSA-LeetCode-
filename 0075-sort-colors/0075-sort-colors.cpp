class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int middle = 0;
        while(middle<=right){
            if(nums[middle] == 0 ){
                swap(nums[left] , nums[middle]);
                left++;
                middle++;
            }

            else if(nums[middle] == 1){
                middle++;
            }
            else{
                swap(nums[right] , nums[middle]);
                right--;
            }
        }
        

        
    }
};