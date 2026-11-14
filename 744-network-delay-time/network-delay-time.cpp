class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
        unordered_map<int, vector<pair<int, int>>> adj;

        for (auto& edge : times)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
        }

        set<pair<int, int>> st;
        vector<int> dist(n + 1, 1e9);

        dist[k] = 0;
        st.insert({0, k});

        while (!st.empty())
        {
            auto it = *(st.begin());
            int d = it.first;
            int node = it.second; 
            st.erase(it);

            for (auto& edge : adj[node])
            {
                int adjNode = edge.first;                
                int wt = edge.second;                
                if (d + wt < dist[adjNode])
                {                    
                    if (dist[adjNode] != 1e9)
                    {                        
                        st.erase({dist[adjNode], adjNode});                    
                    }
                    dist[adjNode] = d + wt;                    
                    st.insert({dist[adjNode], adjNode});                
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (dist[i] == 1e9)
            {
                return -1;
            }
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};