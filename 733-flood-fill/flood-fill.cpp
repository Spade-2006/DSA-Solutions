class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
    {
        queue<pair<int,int>> q;


        int m = image.size();
        int n = image[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        q.push({sr,sc});

        while(!q.empty())
        {
            int currRow = q.front().first;
            int currCol = q.front().second;
            visited[currRow][currCol] = true;
            q.pop();
            if(currRow - 1 >=0 and image[currRow][currCol] == image[currRow-1][currCol])
            {
                if(!visited[currRow-1][currCol])
                    q.push({currRow-1 , currCol});
            }
            if(currCol - 1 >=0 and image[currRow][currCol] == image[currRow][currCol-1])
            {
                if(!visited[currRow][currCol-1])
                    q.push({currRow , currCol-1});
            }
            if(currRow + 1 < image.size() and image[currRow][currCol] == image[currRow+1][currCol])
            {
                if(!visited[currRow+1][currCol])
                    q.push({currRow+1 , currCol});
            }
            if(currCol + 1 < image[0].size()  and image[currRow][currCol] == image[currRow][currCol + 1])
            {
                if(!visited[currRow][currCol+1])
                    q.push({currRow , currCol+1});
            }
            image[currRow][currCol] = color;
        }

        return image;
        
    }
};