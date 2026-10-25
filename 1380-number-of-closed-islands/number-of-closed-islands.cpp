class Solution {
public:
    vector<int> drow = {-1, 0, 1, 0};
    vector<int> dcol = {0, 1, 0, -1};

    
    void bfs(int i, int j,
             vector<vector<int>>& vis,
             vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;

        q.push({i, j});
        vis[i][j] = 1;

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

           
            for (int k = 0; k < 4; k++) {
                int nrow = row + drow[k];
                int ncol = col + dcol[k];

                if (nrow >= 0 && nrow < n &&
                    ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == 0 &&
                    !vis[nrow][ncol]) {

                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int islands = 0;

        
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 0 && !vis[i][0]) {
                bfs(i, 0, vis, grid);
            }

            if (grid[i][m - 1] == 0 && !vis[i][m - 1]) {
                bfs(i, m - 1, vis, grid);
            }
        }

        
        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 0 && !vis[0][j]) {
                bfs(0, j, vis, grid);
            }

            if (grid[n - 1][j] == 0 && !vis[n - 1][j]) {
                bfs(n - 1, j, vis, grid);
            }
        }

        
        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {

                if (grid[i][j] == 0 && !vis[i][j]) {
                    islands++;

                    bfs(i, j, vis, grid);
                }
            }
        }

        return islands;
    }
};