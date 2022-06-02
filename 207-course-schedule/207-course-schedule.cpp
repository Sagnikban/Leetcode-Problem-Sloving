class Solution {
public:
    bool DFSRec(int s,vector<bool> &visited,vector<bool> &currvisited,vector<int>adj[])
    {
        visited[s]=true;
        currvisited[s]=true;
        
        for(auto it:adj[s])
        {
            if(!visited[it])
            {
                if(DFSRec(it,visited,currvisited,adj))
                return true;    
            }
            else if(visited[it]&& currvisited[it])
            return true;    
        }
        
        
        currvisited[s]=false;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        
        for(int i=0;i<prerequisites.size();i++)
        adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
            
       vector<bool>visited(numCourses,false),currvisited(numCourses,false);
        
        for(int i=0;i<numCourses;i++)
        {
            if(!visited[i])
            {
                if(DFSRec(i,visited,currvisited,adj))
                return false;
            }
        }
         
        return true;
        
    }
};