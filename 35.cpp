class Solution {

private:
int largestarea(vector<int>heights,int n) {
        vector<int> left(n), right(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            maxArea = max(maxArea, heights[i] * width);
        }
        return maxArea;
    }
public:

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> intmatrix(n , vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                intmatrix[i][j] = matrix[i][j] - '0';
            }
        }

        int area = largestarea(intmatrix[0], m);

        for(int i = 1;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(intmatrix[i][j]!=0)
                    intmatrix[i][j] = intmatrix[i][j] + intmatrix[i-1][j];
                else
                    intmatrix[i][j] = 0;
            }
            area = max(area,largestarea(intmatrix[i],m));
        }   
        return area;     
    }
};