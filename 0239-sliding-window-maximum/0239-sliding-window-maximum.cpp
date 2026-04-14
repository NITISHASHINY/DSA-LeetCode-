class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> queue; //{value,index}
        vector<int> ans;
        for(int i =0;i<nums.size();i++){
            //push current element
            queue.push({nums[i], i});
            //remove elements outside window
            while(queue.top().second<=i-k){
                queue.pop();
            }
            if(i>=k-1){
                ans.push_back(queue.top().first);
            }
            
        }
        return ans;
        
    }
};