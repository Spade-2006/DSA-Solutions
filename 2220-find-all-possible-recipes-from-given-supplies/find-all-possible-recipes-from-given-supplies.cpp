using namespace std;

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> supply(supplies.begin(), supplies.end());
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> indegree;
        
        for (string r : recipes) {
            indegree[r] = 0;
        }

        for (int i = 0; i < recipes.size(); i++) {
            for (string ing : ingredients[i]) {
                if (supply.count(ing) == 0) {
                    graph[ing].push_back(recipes[i]);
                    indegree[recipes[i]]++;
                }
            }
        }

        queue<string> q;
        for (auto p : indegree) {
            if (p.second == 0) {
                q.push(p.first);
            }
        }

        vector<string> ans;
        while (!q.empty()) {
            string u = q.front();
            q.pop();
            ans.push_back(u);

            for (string v : graph[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return ans;
    }
};