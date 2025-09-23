#include <vector>
#include <algorithm>  // for count
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int val = nums[i];
            int c = count(nums.begin(), nums.end(), val);
            if (c > n / 2) {
                return val;  // majority element found
            }
        }
        return -1; // this line is never reached because majority always exists
    }
};