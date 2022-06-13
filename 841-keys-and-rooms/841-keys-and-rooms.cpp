class Solution {
public:
    void dfs(vector<vector<int>>rooms,int source,vector<bool>&visited)
    {
        visited[source]=true;
        
        for(auto it:rooms[source])
        {
            if(!visited[it])
            dfs(rooms,it,visited);
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