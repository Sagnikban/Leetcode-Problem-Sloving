// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
   int ans=0;
    void dfs(int s,vector<int>adj[],int d,vector<bool>visited)
    {
        visited[s]=true;
        if(s==d)
        ans++;
        
        for(auto it:adj[s])
        {
          if(!visited[it])    
          dfs(it,adj,d,visited);  
        }
        visited[s]=false;
    }
	int possible_paths(vector<vector<int>>edges, int n, int s, int d){
	    // Code here
	    vector<int>adj[n];
	    vector<bool>visited(n,false);
	    for(int i=0;i<edges.size();i++)
	    adj[edges[i][0]].push_back(edges[i][1]);
	    
	    for(int i=0;i<n;i++)
	    {
	        if(i==s)
	        {
	            dfs(i,adj,d,visited);
	        }
	    }
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, s, d;
		cin >> n >> m >> s >> d;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			edges.push_back({u,v});
		}
		Solution obj;
		int ans = obj.possible_paths(edges, n, s, d);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends