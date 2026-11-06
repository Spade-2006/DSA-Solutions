#include <vector>
#include <list>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    bool validPath(int v, vector<vector<int>>& edges, int s, int d) {
        
        if (s == d) return true;

        unordered_map<int, list<int>> adjlist;
        prepareAdjList(adjlist, edges);

        unordered_map<int, bool> visited;

        return BFS(s, d, adjlist, visited);
    }

private:

    bool BFS(int s, int d, unordered_map<int, list<int>>& adjlist, unordered_map<int, bool>& visited) {
        queue<int> nodeq;

        nodeq.push(s);
        visited[s] = true;

        while (!nodeq.empty()) {
            int frontNode = nodeq.front();
            nodeq.pop();

            for (int neighbor : adjlist[frontNode]) {
                if (neighbor == d) {
                    return true;
                }

                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    nodeq.push(neighbor);
                }
            }
        }

        return false; 
    }

    void prepareAdjList(unordered_map<int, list<int>>& adjlist, vector<vector<int>>& edges) {
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int w = edges[i][1];

            adjlist[u].push_back(w);
            adjlist[w].push_back(u);
        }
    }
};