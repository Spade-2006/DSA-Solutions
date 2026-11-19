class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid)
    {
        int row = grid.size();
        int col = grid[0].size();


        int ans = 0;

        for(int i = 0;i<row;i++)
        {
            for(int j = 0;j<col;j++)
            {
                if(grid[i][j] == 1)
                {
                    //up case  
                    if((j == 0) or (j!=0 and grid[i][j-1] == 0))
                        ans++;

                    //down case
                    if((j == col-1) or (j!=col-1 and grid[i][j+1] == 0))
                        ans++;

                    //left
                    if((i == 0) or (i!=0 and grid[i-1][j] == 0))
                        ans++;

                    //right
                    if((i == row-1) or (i!=row-1 and grid[i+1][j] == 0))
                        ans++;
                }
            }
        }

        return ans;
        
    }
};