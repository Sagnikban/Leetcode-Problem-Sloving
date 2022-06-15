class Solution {
public:
    void dfs(int node,vector<pair<int,bool>> adj[],vector<bool> &vis,int &count){
        vis[node] = true;
        for(auto i:adj[node]){
            
            if(!vis[i.first]){
                if(i.second==true){
                    count++;
                }
                dfs(i.first,adj,vis,count);
            }
        }
    }
    
    int minReorder(int n, vector<vector<int>>& c) {
        vector<pair<int,bool>> adj[n];
        for(int i=0;i<c.size();i++){
            adj[c[i][0]].push_back({c[i][1],true});
            adj[c[i][1]].push_back({c[i][0],false});
        }
        
        int count=0;
        vector<bool> vis(n,false);
        dfs(0,adj,vis,count);
        
        return count;
    }
};