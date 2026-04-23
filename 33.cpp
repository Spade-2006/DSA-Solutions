class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();
    
        int maxi = 0;
        int r = 0 ;
        int rc=0;

    for(vector<int> i : mat)
    {
        int count = 0;
        for(int j : i)
        {
            if(j==1)
                count ++;
        }
        if(count > maxi)
        {
            maxi = count;
            r = rc;
        }
        rc++;
    }
     return {r,maxi};

    }

   
};