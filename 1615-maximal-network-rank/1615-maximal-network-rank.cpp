class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>adj[n];
        for(int i=0;i<roads.size();i++)
        {
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }
        
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
               int x=adj[i].size()+adj[j].size();
               sort(adj[i].begin(),adj[i].end());
               if(binary_search(adj[i].begin(),adj[i].end(),j))
               x--;
        
               maxi=max(maxi,x); 
                

            }
        }
        return maxi;
    }
};