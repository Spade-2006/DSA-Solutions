class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1];
            double p = succProb[i];
            adj[u].push_back({v, p});
            adj[v].push_back({u, p});
        }


        priority_queue<pair<double, int>> pq;
        vector<double> maxProb(n, 0.0);

        
        maxProb[start_node] = 1.0;
        pq.push({1.0, start_node});

        while (!pq.empty())
        {
            auto [prob, u] = pq.top();
            pq.pop();


            if (u == end_node) 
                return prob;


            if (prob < maxProb[u]) 
                continue;

            for (auto [v, edgeProb] : adj[u])
            {
                if (prob * edgeProb > maxProb[v])
                {
                    maxProb[v] = prob * edgeProb;
                    pq.push({maxProb[v], v});
                }
            }
        }

        return 0.0;
    }
};