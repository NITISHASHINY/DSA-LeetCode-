class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int>Indegree(numCourses , 0);

        for(auto it : prerequisites){
            int course = it[0];
            int prerequisite = it[1];
            adj[prerequisite].push_back(course);
            Indegree[course]++;
        }
        queue<int>q;
        for(int i = 0 ; i < numCourses ; i++){
            if(Indegree[i] == 0){
                q.push(i);
            }
        }
        int count = 0 ;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;

            for(auto neighbour : adj[node]){
                Indegree[neighbour]--;
                if(Indegree[neighbour] == 0){
                    q.push(neighbour);
                }
            }
        }
        return count == numCourses;

    }
};