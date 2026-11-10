class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time)
    {

        unordered_map<int , vector<int>> adj;

        for(int i = 0; i < relations.size() ; i++)
        {
            int  u = relations[i][0];
            int  v = relations[i][1];

            adj[u].push_back(v);
        }

        vector<int> indegree(n+1);

        for(auto i : adj)
        {
            for(int j : i.second)
                indegree[j]++;
        }

        queue<int>  q;
        for(int i = 1 ; i<=n ; i++)
        {
            if(indegree[i] == 0)
                q.push(i);
        }

        vector<int> t = time;

        t.insert(t.begin() , 0);

        while(!q.empty())
        {
            int course = q.front();
            q.pop();

            for(int nextcourse : adj[course])
            {
                t[nextcourse] = max(t[nextcourse] , t[course] + time[nextcourse - 1]);
                indegree[nextcourse]--;
                if (indegree[nextcourse] == 0)
                {
                    q.push(nextcourse);
                }



            }

        }

        return *max_element(t.begin(), t.end());
        
    }
};