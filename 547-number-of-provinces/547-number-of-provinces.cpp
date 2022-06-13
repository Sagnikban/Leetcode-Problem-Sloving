class Solution {
public:
    void dfs(vector<int>adj[],int source,vector<bool>&visited)
    {
        visited[source]=true;
        for(int it:adj[source])
        {
            if(!visited[it])
            dfs(adj,it,visited);
        }
        
            
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n=isConnected.size();
        vector<int>adj[n+1];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]!=0 && i!=j)
                {
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }    
                    
            }
        }
        int ans=0;
        
        vector<bool>visited(n+1,false);
        
       
        for(int i=1;i<=n;i++)
        {
          if(!visited[i]) 
          {
             
              dfs(adj,i,visited);
              
               ans++;
             
          }
          
        }
        return ans;
    }
};