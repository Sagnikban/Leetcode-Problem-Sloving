class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        vector<int>adj[n];
        
        for(int i=0;i<edges.size();i++)
        {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
        }
        
           vector<int>vis(n+1,0);
     
            queue<int>q;
            q.push(source);
            vis[source]=1;
            while(!q.empty())
            {
                int node=q.front();
                q.pop();
                
                for(auto it:adj[node])
                {
                    if(!vis[it])
                    {
                        q.push(it);
                        vis[it]=1;
                    }
                }
            }
        
        
        if(vis[destination]==1)
        return true;
        
        return false;
        
    }
};