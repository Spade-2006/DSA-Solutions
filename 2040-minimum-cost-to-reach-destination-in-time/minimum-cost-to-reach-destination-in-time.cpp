class Solution {
public:
    int n;
    vector<vector<array<int, 3>>> adj;
    vector<vector<int>> dp;
    const int INF = 1e9;

    int solve(int node, int timeSpent, int maxTime)
    {
        if (timeSpent > maxTime)
            return INF;
        
        if (node == n - 1) 
            return 0;
        
        if (dp[node][timeSpent] != -1) 
            return dp[node][timeSpent];
        
        int minCost = INF;
        for (auto [dest, time, price] : adj[node])
        {
            if (timeSpent + time <= maxTime)
            {
                int nextCost = solve(dest, timeSpent + time, maxTime);
                if (nextCost != INF)
                {
                    minCost = min(minCost, price + nextCost);
                }
            }
        }
        
        return dp[node][timeSpent] = minCost;
    }

    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        n = passingFees.size();
        adj.resize(n);
        
    
        for (auto edge : edges) {
            int u = edge[0], v = edge[1], t = edge[2];
            adj[u].push_back({v, t, passingFees[v]});
            adj[v].push_back({u, t, passingFees[u]});
        }
        
        dp.assign(n, vector<int>(maxTime + 1, -1));
        
        
        int ans = solve(0, 0, maxTime);
        return (ans >= INF) ? -1 : passingFees[0] + ans;
    }
};