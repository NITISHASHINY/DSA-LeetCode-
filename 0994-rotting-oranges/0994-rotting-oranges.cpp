class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int,int>> q;
        int fresh = 0;

        // Step 1: collect rotten + count fresh
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        int minutes = 0;
        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        // Step 2: BFS
        while(!q.empty() && fresh > 0){
            int size = q.size();
            minutes++;

            for(int i = 0; i < size; i++){
                auto front = q.front();
                q.pop();

                int r = front.first;
                int c = front.second;

                for(auto d : dir){
                    int nr = r + d.first;
                    int nc = c + d.second;

                    if(nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        fresh--;
                    }
                }
            }
        }

        // Step 3: result
        if(fresh > 0) return -1;
        return minutes;
    }
};