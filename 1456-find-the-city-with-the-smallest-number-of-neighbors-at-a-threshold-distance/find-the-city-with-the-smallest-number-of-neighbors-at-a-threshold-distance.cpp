class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int d) {
        const int INF = 1e9;
        vector<vector<int>> adj(n, vector<int>(n, INF));

        for (int i = 0; i < n; i++)
        {
            adj[i][i] = 0;
        }

        for (const auto& a : edges)
        {
            int u = a[0];
            int v = a[1];
            int w = a[2];

            adj[u][v] = w;
            adj[v][u] = w;
        }

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (adj[i][k] < INF && adj[k][j] < INF)
                    {
                        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                    }
                }
            }
        }

        int ans = 0;
        int mini = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            int curr = 0;
            for (int j = 0; j < n; j++)
            {
                if (adj[i][j] <= d)
                {
                    curr++;
                }
            }

            if (curr <= mini)
            {
                mini = curr;
                ans = i;
            }
        }

        return ans;
    }
};