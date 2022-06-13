class Solution {
public:
    void dfs(vector<vector<int>>adj,int source,vector<bool>&visited)
    {
        visited[source]=true;
        
        for(auto it:adj[source])
        {
            if(!visited[it])
            dfs(adj,it,visited);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n=rooms.size();
     
        
        vector<bool>visited(n,false);
        
 
        dfs(rooms,0,visited);
       
        
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            return false;    
        }
        
        return true;
    }
};