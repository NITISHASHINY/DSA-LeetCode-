class Solution {
public:

    bool isSafe(int node, vector<vector<int>>& graph,
                vector<int>& vis,
                vector<int>& pathVis,
                vector<int>& check) {

        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;

        for (auto neighbour : graph[node]) {

            if (!vis[neighbour]) {

                if (isSafe(neighbour, graph, vis, pathVis, check))
                    return true;

            }
            else if (pathVis[neighbour]) {

                return true;
            }
        }

        check[node] = 1;
        pathVis[node] = 0;

        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int V = graph.size();

        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        vector<int> check(V, 0);

        vector<int> ans;

        for (int i = 0; i < V; i++) {

            if (!vis[i]) {

                isSafe(i, graph, vis, pathVis, check);

            }
        }

        for (int i = 0; i < V; i++) {

            if (check[i])

                ans.push_back(i);
        }

        return ans;
    }
};