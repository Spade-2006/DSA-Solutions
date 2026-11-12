class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        
        
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }

        vector<vector<int>> visited = grid;
        
        
        map<pair<int, int>, pair<int, int>> parent;
        parent[{0, 0}] = {-1, -1};

        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = 1;

        while (!q.empty()) 
        {
            auto [row, col] = q.front();
            q.pop();

            
            if (row == n - 1 && col == n - 1) {
                break;
            }

            
            if (row > 0 && !visited[row - 1][col]) {
                q.push({row - 1, col});
                visited[row - 1][col] = 1;
                parent[{row - 1, col}] = {row, col};
            }
            
            if (row < n - 1 && !visited[row + 1][col]) {
                q.push({row + 1, col});
                visited[row + 1][col] = 1;
                parent[{row + 1, col}] = {row, col};
            }
         
            if (col > 0 && !visited[row][col - 1]) {
                q.push({row, col - 1});
                visited[row][col - 1] = 1;
                parent[{row, col - 1}] = {row, col};
            }
          
            if (col < n - 1 && !visited[row][col + 1]) {
                q.push({row, col + 1});
                visited[row][col + 1] = 1;
                parent[{row, col + 1}] = {row, col};
            }
            if (row > 0 && col > 0 && !visited[row - 1][col - 1]) {
                q.push({row - 1, col - 1});
                visited[row - 1][col - 1] = 1;
                parent[{row - 1, col - 1}] = {row, col};
            }
            
            if (row > 0 && col < n - 1 && !visited[row - 1][col + 1]) {
                q.push({row - 1, col + 1});
                visited[row - 1][col + 1] = 1;
                parent[{row - 1, col + 1}] = {row, col};
            }
            if (row < n - 1 && col > 0 && !visited[row + 1][col - 1]) {
                q.push({row + 1, col - 1});
                visited[row + 1][col - 1] = 1;
                parent[{row + 1, col - 1}] = {row, col};
            }
         
            if (row < n - 1 && col < n - 1 && !visited[row + 1][col + 1]) {
                q.push({row + 1, col + 1});
                visited[row + 1][col + 1] = 1;
                parent[{row + 1, col + 1}] = {row, col};
            }
        }

     
        if (parent.find({n - 1, n - 1}) == parent.end()) {
            return -1;
        }

        int length = 0;
        pair<int, int> curr = {n - 1, n - 1};
        
        while (curr != make_pair(-1, -1)) {
            length++;
            curr = parent[curr];
        }

        return length;
    }
};