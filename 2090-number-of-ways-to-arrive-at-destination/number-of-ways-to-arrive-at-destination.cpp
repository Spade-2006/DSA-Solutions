class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads)
    {
        const int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> adj(n);

        for (auto& edge : roads)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        set<pair<long long, int>> st;
        vector<long long> dist(n, 1e18);
        vector<int> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;
        st.insert({0, 0});

        while (!st.empty())
        {
            auto it = *(st.begin());
            long long d = it.first;
            int node = it.second;
            st.erase(it);

            for (auto& edge : adj[node])
            {
                int adjNode = edge.first;
                long long wt = edge.second;

                
                if (d + wt < dist[adjNode])
                {
                    if (dist[adjNode] != 1e18)
                    {
                        st.erase({dist[adjNode], adjNode});
                    }
                    dist[adjNode] = d + wt;
                    ways[adjNode] = ways[node];
                    st.insert({dist[adjNode], adjNode});
                }
                // Case 2: Another path with the exact same shortest distance
                else if (d + wt == dist[adjNode])
                {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};