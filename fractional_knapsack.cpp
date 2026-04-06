#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        
        int n = val.size();
        
        // Step 1: store (ratio, weight)
        vector<pair<double, int>> knapsack;
        
        for(int i = 0; i < n; i++){
            double ratio = (double)val[i] / wt[i];
            knapsack.push_back({ratio, wt[i]});
        }
        
        // Step 2: sort by ratio descending
        sort(knapsack.begin(), knapsack.end(), greater<pair<double,int>>());
        
        double final_val = 0.0;
        
        // Step 3: traverse
        for(int i = 0; i < n; i++){
            
            double ratio = knapsack[i].first;
            int curr_wt = knapsack[i].second;
            
            // take full item
            if(curr_wt <= capacity){
                final_val += ratio * curr_wt;  // value = ratio * weight
                capacity -= curr_wt;
            }
            else{
                // take fraction
                final_val += ratio * capacity;
                break;
            }
        }
        
        return final_val;
    }
};