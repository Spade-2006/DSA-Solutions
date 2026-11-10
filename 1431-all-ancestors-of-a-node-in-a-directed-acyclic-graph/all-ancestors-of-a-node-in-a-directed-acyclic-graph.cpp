class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>> ans(n);

        unordered_map<int,vector<int>> adj;

        for(vector<int> i : edges)
        {
            int u = i[0];
            int v = i[1];

            adj[v].push_back(u);
        }

        for(int i = 0 ; i < n  ; i++)
        {
            set<int> curr;
            vector<bool> visited(n);
            dfs(adj , i ,  curr,visited);
            vector<int> t(curr.begin() ,  curr.end());
            ans[i] = t;
        }

        return ans;   
    }

    void dfs(unordered_map<int,vector<int>> &adj , int i, set<int> &curr,vector<bool> &visited)
    {
        if(adj[i].empty())
            return;
        visited[i] = true;

        for(int n : adj[i])
        {
            if(!visited[n])
            {
                curr.insert(n);
                dfs(adj , n , curr,visited);
            }
        }    
    }
};