class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int color[graph.size()];
        
        memset(color,-1,sizeof color);
        for(int j=0;j<graph.size();j++)
        {
            if(color[j]==-1)
            {
                if(!bipartiteBfs(j,graph,color))
                return false;    
            }
        }
        
        return true;
    }
    
    bool bipartiteBfs(int src,vector<vector<int>>adj,int color[])
    {
        queue<int>q;
        q.push(src);
        color[src]=1;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it:adj[node])
            {
                if(color[it]==-1)
                {
                    color[it]=1-color[node];
                    q.push(it);
                }
                else if(color[it]==color[node])
                return false;    
                    
            }
            
        }
        
        return true;
    }
};