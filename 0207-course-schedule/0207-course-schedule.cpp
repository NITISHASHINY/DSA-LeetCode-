#include <vector>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Build adjacency list for the graph
        vector<vector<int>> graph(numCourses);
        for (const auto& pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
        }

        // State vector: 0 = unvisited, 1 = visiting, 2 = visited
        vector<int> state(numCourses, 0);

        // Check each course for cycles
        for (int i = 0; i < numCourses; ++i) {
            if (hasCycle(i, graph, state))
                return false; // cycle detected
        }
        return true; // no cycle found, can finish all courses
    }

private:
    bool hasCycle(int node, const vector<vector<int>>& graph, vector<int>& state) {
        if (state[node] == 1) return true;   // cycle detected
        if (state[node] == 2) return false;  // already visited, no cycle here

        state[node] = 1; // mark as visiting
        for (int neighbor : graph[node]) {
            if (hasCycle(neighbor, graph, state))
                return true;
        }
        state[node] = 2; // mark as visited
        return false;
    }
};