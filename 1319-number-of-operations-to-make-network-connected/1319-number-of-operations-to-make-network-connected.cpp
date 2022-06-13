class Solution {
public:
    void dfs(int src,vector<int>g[],vector<bool>&vis)
{
    vis[src]=true;
    for(auto it:g[src])
    {
        if(!vis[it])
        {
            dfs(it,g,vis);
        }
    }
}

int makeConnected(int n, vector<vector<int>>& connections) 
{
    vector<int>adj[n];
    int m=connections.size();
    if(m<n-1)return -1;
    for(int i=0;i<m;i++)
    {
        adj[connections[i][1]].push_back(connections[i][0]);
        adj[connections[i][0]].push_back(connections[i][1]);
    }
    vector<bool>vis(n,false);
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            c++;
            dfs(i,adj,vis);
        }
    }
    return c-1;
}
};