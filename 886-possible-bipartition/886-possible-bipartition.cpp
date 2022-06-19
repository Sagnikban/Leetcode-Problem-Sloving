class Solution {
public:
  bool isCheckPossible(vector<vector<int>>adj,int n,int node,vector<int>&color)
{
    queue<int>q;
    q.push(node);
    color[node]= 1;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto it:adj[node])
        {
            if(color[it]==-1)
            {
                q.push(it);
                color[it]=1-color[node];
            }
            else if(color[it]==color[node])
            {
                return false;
            }
        }
    }
    return true;
}


bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
    
    vector<vector<int>>adj(n+1);
    
    int m=dislikes.size();
    for(int i=0;i<m;i++)
    {
        adj[dislikes[i][0]].push_back(dislikes[i][1]);
        adj[dislikes[i][1]].push_back(dislikes[i][0]);
    }
    
    vector<int>color(n+1,-1);
    
    for(int i=1;i<=n;i++)
    {
        if(color[i]==-1)
        {
            if(!isCheckPossible(adj,n,i,color)) return false;
        }
    }
    return true;
}
};