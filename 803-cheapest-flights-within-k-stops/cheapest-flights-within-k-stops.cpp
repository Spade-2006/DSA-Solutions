class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        const int INF = 1e8;
        vector<int> dist(n, INF);        
        dist[src] = 0;

        
         for (int i = 0; i < k+1; i++)
        {
            vector<int> temp_prices = dist;            
            for (auto edge : flights)            
            {
                int u = edge[0];
                int v = edge[1];   
                int cost = edge[2];
                if (dist[u] != INF && dist[u] + cost < temp_prices[v])
                {
                    temp_prices[v] = dist[u] + cost;
                }         
            }  
            dist = temp_prices;     
        }


       return dist[dst] == INF ? -1 : dist[dst];





        
    }
};