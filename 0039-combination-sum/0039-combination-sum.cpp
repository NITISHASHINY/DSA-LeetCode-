class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //creating final array
        vector<vector<int>> ans;
        //array of combinations
        vector<int> comb;
        FinalArray(target, 0 , candidates, comb, ans );
        return ans;

    
         
        
    }
    //main function
    void FinalArray(int target, int index, vector<int>& candidates, vector<int>& comb, vector<vector<int>>& ans){
        //push empty arrays
        //corrected base case
        if(target == 0){
            ans.push_back(comb);
            return;

        }
        //stop recursion
        if(target < 0) return;
        
        for(int i = index; i<candidates.size(); i++){
            comb.push_back(candidates[i]);
            FinalArray(target - candidates[i], i, candidates, comb, ans);
            comb.pop_back();
        }
    }
};