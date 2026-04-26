class Solution {
public:

    int countsmall(int mid,int m , int n)
    {
        int totalcount =0;

        for(int i = 1; i<=m;i++ )
        {
            int count = min((mid/i),n);
            totalcount += count; 

        }
        return totalcount;
    }
    int findKthNumber(int m, int n, int k) {


        int low = 1;
        int high = m*n;


        while(low<high)
        {
            int mid = (low+high)/2;
            int count = countsmall(mid,m,n);

            if(count>=k)
            {
                high = mid;
            }
            else
            {
                low = mid+1;
            }



        }

        return low;
        
    }
};