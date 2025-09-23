#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int start = 0;       
        int middle = 0;         
        int end = n - 1;        

        while (middle <= end) {
            if (nums[middle] == 0) {
                swap(nums[start], nums[middle]);
                start++;
                middle++;
            }
            else if (nums[middle] == 1) {
                middle++;
            }
            else { // nums[middle] == 2
                swap(nums[middle], nums[end]);
                end--;
            }
        }
    }
};