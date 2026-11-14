class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
        // 1. Direct vector indexing instead of unordered_map
        vector<vector<pair<int, int>>> adj(n + 1);

        for (const auto& edge : times)
        {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        // 2. Min-heap (priority_queue) instead of std::set
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n + 1, 1e9);

        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty())
        {
            auto [d, node] = pq.top();
            pq.pop();

            // Skip stale entries
            if (d > dist[node]) continue;

            for (const auto& [adjNode, wt] : adj[node])
            {
                if (d + wt < dist[adjNode])
                {
                    dist[adjNode] = d + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (dist[i] == 1e9) return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};