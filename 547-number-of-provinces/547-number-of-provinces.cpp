class Solution {
public:
   void dfs(vector<int> adj[], vector<bool> &visited, int src)
    {
        visited[src]=true;
        
        for(int v:adj[src])
        {
            if(!visited[v])
                dfs(adj, visited, v);
        }
    }
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int>adj[isConnected.size()+1];
        
        for(int i=0;i<isConnected.size();i++)
        {
            for(int j=0;j<isConnected[i].size();j++)
            {
                if(i!=j && isConnected[i][j]!=0)
                {
                    adj[i+1].push_back(j+1);
                }
            }
        }
        
        vector<bool>visited(isConnected.size()+1, false);
        
        int cnt=0;
        for(int i=1;i<isConnected.size()+1;i++)
        {
            if(!visited[i])
            {
                cnt++;
                dfs(adj, visited, i);
            }
                
        }
        return cnt;
        
    }
};