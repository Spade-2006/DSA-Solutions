class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance)
    {
        vector<vector<char>> visited = maze;
        int m = maze.size();
        int n = maze[0].size();

        int row = entrance[0];
        int col = entrance[1];

        if(visited[row][col] == '+')
            return -1;

        visited[row][col] = '+';
        queue<pair<int,int>> q;

        q.push({row,col});

        map<pair<int,int>, pair<int,int>> parent;
        parent[{row,col}] = {-1,-1};
        pair<int,int> exitCell = {-1,-1};

        while(!q.empty())
        {
            auto [r,c] = q.front();
            q.pop();

            if((r == 0 or r == m-1 or c == 0 or c == n-1) and !(r == row and c == col))
            {
                exitCell = {r,c};
                break;
            }

            if(r > 0 and visited[r-1][c] == '.')
            {
                visited[r-1][c]  = '+';
                parent[{r-1,c}] = {r,c};
                q.push({r-1,c});
            }
            if(c > 0 and visited[r][c-1] == '.')
            {
                visited[r][c-1]  = '+';
                parent[{r,c-1}] = {r,c};
                q.push({r,c-1});
            }
            if(c <n-1 and visited[r][c+1] == '.')
            {
                visited[r][c+1]  = '+';
                parent[{r,c+1}] = {r,c};
                q.push({r,c+1});
            }
            if(r < m-1 and visited[r+1][c] == '.')
            {
                visited[r+1][c]  = '+';
                parent[{r+1,c}] = {r,c};
                q.push({r+1,c});
            }
        }

        if(exitCell == make_pair(-1,-1))
            return -1;

        int steps = 0;
        pair<int,int> curr = exitCell;
        while(curr != make_pair(row, col))
        {
            steps++;
            curr = parent[curr];
        }

        return steps;
        
    }
};