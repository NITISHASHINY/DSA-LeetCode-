class Solution {
  public:
    vector<int> subsetSums(vector<int>& arr) {
        vector<int> sums_array;  // stores all subset sums
        int n = arr.size();
        
        // start recursion from index 0 with sum 0
        Value(0, n, arr, sums_array, 0);
        
        return sums_array;
    }

    void Value(int index, int n, vector<int>& arr, vector<int>& sums_array, int sum) {
        
        // base case: all elements considered, record this subset's sum
        if (index == n) {
            sums_array.push_back(sum);
            return;
        }

        // EXCLUDE current element, move to next
        Value(index + 1, n, arr, sums_array, sum);

        // INCLUDE current element, add to sum and move to next
        Value(index + 1, n, arr, sums_array, sum + arr[index]);
    }
};
