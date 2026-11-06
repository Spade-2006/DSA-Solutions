class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();


        int count = 0;

        vector<vector<bool>> visited(n , vector<bool>(m , false));


        for(int i = 0 ; i<n;i++)
        {
            for(int j = 0 ; j<m ; j++)
            {
                if(!visited[i][j] and grid[i][j] == 1)
                {
                    int curr = 0;
                    dfs(grid , visited , i , j , n ,m, curr);
                    count = max(curr , count);
                }
            }
        }

        return count ;
        
    }

    void dfs(vector<vector<int>>& grid ,vector<vector<bool>> &visited , int i , int j , int n , int m,int &count)
    {


        if(i>=n or j>=m or i<0 or j<0)
            return;
        if (grid[i][j] == 0 || visited[i][j])
            return;

       
        visited[i][j] = true;
        count++;

        dfs(grid , visited , i+1 , j , n , m,count);
        dfs(grid , visited , i-1 , j , n , m,count);
        dfs(grid , visited , i , j+1 , n , m,count);
        dfs(grid , visited , i , j-1 , n , m,count);

    }



};