#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> jobSequencing(vector<int>& deadline, vector<int>& profit) {
        
        int n = deadline.size();
        
        // Step 1: Store (profit, deadline)
        vector<pair<int,int>> jobs;
        for(int i = 0; i < n; i++) {
            jobs.push_back({profit[i], deadline[i]});
        }
        
        // Step 2: Sort by profit (descending)
        sort(jobs.begin(), jobs.end(), greater<pair<int,int>>());
        
        // Step 3: Find max deadline
        int maxDeadline = 0;
        for(int i = 0; i < n; i++) {
            maxDeadline = max(maxDeadline, jobs[i].second);
        }
        
        // Step 4: Create slots
        vector<int> slot(maxDeadline + 1, -1);
        
        int countJobs = 0;
        int totalProfit = 0;
        
        // Step 5: Schedule jobs
        for(int i = 0; i < n; i++) {
            
            int currProfit = jobs[i].first;
            int currDeadline = jobs[i].second;
            
            // place in latest free slot
            for(int j = currDeadline; j > 0; j--) {
                if(slot[j] == -1) {
                    slot[j] = 1;
                    countJobs++;
                    totalProfit += currProfit;
                    break;
                }
            }
        }
        
        return {countJobs, totalProfit};
    }
};