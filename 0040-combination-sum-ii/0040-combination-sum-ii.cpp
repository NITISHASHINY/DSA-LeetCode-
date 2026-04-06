class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> comb;
        //no duplicates 
        sort(candidates.begin(), candidates.end());
        FinalArray(0, target, candidates, ans, comb);
        return ans;

        
        
    }
    void FinalArray(int index, int target, vector<int>& candidates, vector<vector<int>>& ans, vector<int>& comb){
        if(target == 0){
            ans.push_back(comb);
            return;
        }
        if(target<0)return;
        for(int i = index; i<candidates.size(); i++){
            //remove duplicates
            if(i > index && candidates[i] == candidates[i-1]) continue;
            comb.push_back(candidates[i]);
            FinalArray(i+1, target - candidates[i], candidates, ans, comb  );
            comb.pop_back();
        }
        

    }
};