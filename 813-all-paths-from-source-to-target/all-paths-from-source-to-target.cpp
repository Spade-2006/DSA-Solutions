class Solution {
public:

    void makeAdj(vector<vector<int>>& graph , unordered_map<int , vector<int>> &adj)
    {
        for(int i = 0; i<graph.size() ; i++)
        {
            adj[i] = graph[i];
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
    {
        unordered_map<int , vector<int>> adj;
        makeAdj(graph , adj);

        vector<vector<int>> ans;
        vector<int> curr;
       
        curr.push_back(0);
       
        dfs(adj , ans , curr , 0 , graph.size());

        return ans;
        
    }

    void dfs(unordered_map<int , vector<int>> &adj ,vector<vector<int>> &ans ,vector<int> curr , int index , int n )
    {
        if(index > n or index < 0)
            return;
        
        if(index == n-1)
        {
            ans.push_back(curr);
            return;
        }

        for(int i : adj[index])
        {
           
            curr.push_back(i);
           
            dfs(adj , ans , curr , i , n);
            curr.pop_back();
        }
        
    }
};