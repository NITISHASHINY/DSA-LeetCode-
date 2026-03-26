class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        //creating the final array 
        vector<vector<int>> ans;
        //subsets array
        vector<int> ds;
        //sort for duplicates
        sort(nums.begin(), nums.end());
        //call main function
        solve(0, nums, ds, ans);

        return ans;
    }
    //main
    //create the recursive function
    void solve(int ind ,vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans){
        //push empty array first as it is also considered
        ans.push_back(ds);
        for(int i = ind; i< nums.size(); i++){
            if(i > ind && nums[i] == nums[i-1]) continue;
            ds.push_back(nums[i]);
            solve(i+1, nums, ds, ans);
            ds.pop_back();
        }
    }
        

        
    
};