#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i;
        vector<int> merged(m+n);
        
        // copy only the first m elements of nums1
        copy(nums1.begin(), nums1.begin() + m, merged.begin());
        
        // copy all n elements of nums2
        copy(nums2.begin(), nums2.begin() + n, merged.begin() + m);
        
        sort(merged.begin(), merged.begin() + (m+n));
        for(i = 0; i < m+n; i++){
            nums1[i] = merged[i];
        }
    }
};