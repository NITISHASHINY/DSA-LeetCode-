class Solution {
public:

    void dfs(int node, vector<vector<int>>& isConnected, vector<int>& vis) {
        vis[node] = 1;
        for (int neighbour = 0; neighbour < isConnected.size(); neighbour++) {
            if (isConnected[node][neighbour] == 1 && !vis[neighbour]) {
                dfs(neighbour, isConnected, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int> vis(V, 0);
        int provinces = 0;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                provinces++;
                dfs(i, isConnected, vis);
            }
        }
        return provinces;
    }
};