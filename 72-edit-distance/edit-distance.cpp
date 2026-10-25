class Solution {
public:
    int minDistance(string word1, string word2)
    {
        vector<vector<int>> dp(word1.length()+1 , vector<int>(word2.length()+1 , -1));
        return solve(word1 , word2 , 0 , 0 , dp);
    }

    int solve(string &w1 , string &w2 , int i , int j , vector<vector<int>> &dp)
    {
        if(i == w1.length())
        {
            return w2.length()-j;
        }
        if(j == w2.length())
        {
            return w1.length()-i;
        }

        if(dp[i][j] != -1)
            return dp[i][j];

        if(w1[i] == w2[j])
        {
            return dp[i][j] = solve(w1 , w2 , i+1 , j+1,dp);
        }
        

        int ins = 1 + solve(w1,w2 , i+1 , j , dp);
        int del = 1 + solve(w1,w2,i,j+1 , dp);
        int rep = 1 + solve(w1,w2,i+1,j+1 , dp);


        return dp[i][j]=min({ins , del , rep});
    }
};