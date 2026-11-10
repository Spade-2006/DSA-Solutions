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
            vector<int> curr;
            vector<bool> visited(n);
            dfs(adj , i ,  curr,visited);
            sort(curr.begin(),curr.end());
            ans[i] = curr;
        }

        return ans;   
    }

    void dfs(unordered_map<int,vector<int>> &adj , int i, vector<int> &curr,vector<bool> &visited)
    {
        if(adj[i].empty())
            return;
        

        for(int n : adj[i])
        {
            if(!visited[n])
            {
                visited[n] = true;
                curr.push_back(n);
                dfs(adj , n , curr,visited);
            }
        }    
    }
};