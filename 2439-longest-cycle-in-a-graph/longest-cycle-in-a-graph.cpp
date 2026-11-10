class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> visited(n, false);
        int ans = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                unordered_map<int, int> stepMap;
                
                int temp = DFS(visited, stepMap, i, edges, 0);

                if (temp != -1) {
                    ans = max(ans, temp);
                }
            }
        }

        return ans;
    }

    int DFS(vector<bool>& visited, unordered_map<int, int>& stepMap, int curr, const vector<int>& edges, int step) {
        
        if (curr == -1) {
            return -1;
        }

        
        if (stepMap.count(curr)) {
            return step - stepMap[curr];
        }

        
        if (visited[curr]) {
            return -1;
        }

       
        visited[curr] = true;
        stepMap[curr] = step;

        return DFS(visited, stepMap, edges[curr], edges, step + 1);
    }
};