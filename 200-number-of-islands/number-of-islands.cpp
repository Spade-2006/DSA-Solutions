class Solution {
public:
    int numIslands(vector<vector<char>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();


        int count = 0;

        vector<vector<bool>> visited(n , vector<bool>(m , false));


        for(int i = 0 ; i<n;i++)
        {
            for(int j = 0 ; j<m ; j++)
            {
                if(!visited[i][j] and grid[i][j] == '1')
                {
                    dfs(grid , visited , i , j , n , m);
                    count++;
                }
            }
        }

        return count ;
        
    }

    void dfs(vector<vector<char>>& grid ,vector<vector<bool>> &visited , int i , int j , int n , int m)
    {


        if(i>=n or j>=m or i<0 or j<0)
            return;
        if (grid[i][j] == '0' || visited[i][j])
            return;

       
        visited[i][j] = true;

        dfs(grid , visited , i+1 , j , n , m);
        dfs(grid , visited , i-1 , j , n , m);
        dfs(grid , visited , i , j+1 , n , m);
        dfs(grid , visited , i , j-1 , n , m);

    }



};