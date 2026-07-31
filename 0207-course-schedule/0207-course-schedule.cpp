class Solution {
public:
    bool dfs(int node , vector<vector<int>>& adj , vector<int>& vis, vector<int>& pathVis){

        vis[node] = 1;
        pathVis[node] = 1;
        for(auto neighbour : adj[node]){
            if(!vis[neighbour]){
                if(dfs(neighbour , adj , vis , pathVis))
                return true;
            }
            else if(pathVis[neighbour]){
                return true;
            }
        }
        pathVis[node] = 0;
        return false;
        
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto it : prerequisites){
            int course = it[0];
            int prerequisite = it[1];
            adj[prerequisite].push_back(course);
        }
        vector<int> vis(numCourses , 0);
        vector<int> pathVis(numCourses, 0);

        for(int i = 0 ; i<numCourses; i++){
            if(!vis[i]){
                if(dfs(i , adj , vis , pathVis))
                return false;
            }
        }
        return true;

        
    }
};