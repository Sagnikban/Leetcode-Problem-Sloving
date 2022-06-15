class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        vector<int>adj[n];
        for(int i=0;i<n;i++)
        {
             if(manager[i] != -1)
            adj[manager[i]].push_back(i);
            
        }
        queue<pair<int,int>> q;
        q.push({headID,0});
        
        int tt= 0 ;
        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            tt = max (tt,j);
            vector<int> sub = adj[i];
            for(auto it:adj[i]) {
                q.push({it,j+informTime[i]});
            }
        }
        return tt;
    }
};