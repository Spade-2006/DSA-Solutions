class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        int n = rooms.size();

        vector<bool> visited(n , false);   
      
      

        queue<int> q;


        q.push(0);

        while(!q.empty())
        {
            int currI = q.front();
            q.pop();
            visited[currI] = true;



            vector<int> Keys = rooms[currI];
            for(int x : Keys)
            {
                if(!visited[x])
                    q.push(x);
            }
        } 

        for(bool v : visited)
        {
            if(!v)
                return false;
        } 

        return true;
    }
};