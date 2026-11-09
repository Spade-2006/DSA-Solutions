#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            
            unordered_map<int, bool> visited;
            unordered_map<int, int> parent;

            adj[u].push_back(v);
            adj[v].push_back(u);

            
            vector<int> ans = bfs(adj, visited, parent, u);
            if (!ans.empty())
            {
                return edges[i];
            }
        }

        return {};
    }

    vector<int> bfs(unordered_map<int, vector<int>>& adj, 
                    unordered_map<int, bool>& visited, 
                    unordered_map<int, int>& parent, 
                    int i)
    {
        queue<int> q;
        visited[i] = true;
        parent[i] = -1;
        q.push(i);

        while (!q.empty())
        {
            int f = q.front();
            q.pop();

            for (int neigh : adj[f])
            {
                if (visited[neigh] && parent[f] != neigh)
                {
                    return {neigh, f};
                }
                else if (!visited[neigh])
                {
                    q.push(neigh);
                    visited[neigh] = true;
                    parent[neigh] = f;
                }
            }
        }

        return {};
    }
};