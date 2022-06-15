class Solution {
public:
    bool DfsRec(int s,vector<bool>&visited,vector<bool>&dfsvisited,vector<vector<int>>& graph,vector<bool>&present_cycle)
    {
        visited[s]=true;
        dfsvisited[s]=true;
        
        
        
        for(auto x: graph[s]){
            if(!visited[x]){
                if(DfsRec(x, visited, dfsvisited, graph, present_cycle)){
                    return present_cycle[s] = true;
                }
            }
            else if(visited[x] && dfsvisited[x]){
                return present_cycle[s] = true;
            }
        }
        dfsvisited[s]=false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>ans;
        int n=graph.size();
        vector<bool>present_cycle(n,false);
        vector<bool>visited(n,false),dfsvisited(n,false);
        
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                DfsRec(i,visited,dfsvisited,graph,present_cycle);
            }
        }
        
        
        
        for(int i=0;i<n;i++)
        {
            if(present_cycle[i]==false)
            ans.push_back(i);    
        }
        return ans;
    }
};