// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {

public:
bool demand =false;
    long long dfs( int S,vector<long long>adj[],vector<bool>visited,int *Cap )
    {
        visited[S]=true;
        long long ans=0;
        long long cnt=0;;
        for(auto it:adj[S])
        {
            if(!visited[it])
            {
                cnt++;
            
            long long capacity=dfs(it,adj,visited,Cap);
            
            ans=max(ans,capacity);
            }
        }
        long long req=cnt*ans+Cap[S-1];
        
        if(req>1e18)
        demand =true;
        
        return req;
        
    }
    long long minimum_amount(vector<vector<int>> &Edges, int N, int S, int *Cap){
       // Code here
       vector<long long>adj[N+1];
       vector<bool>visited(N+1,false);
       
       for(int i=0;i<Edges.size();i++)
       {
         adj[Edges[i][0]].push_back(Edges[i][1]);
         adj[Edges[i][1]].push_back(Edges[i][0]);
         
       }
       
       if(dfs(S,adj,visited,Cap)>1e18 || demand)
       return -1;
       
       return dfs(S,adj,visited,Cap);
    }
};

// { Driver Code Starts.


int main()
 {
	int T;
	cin>> T;
	while (T--)
	{
	    int num, start;
	    cin>>num>>start;
	    int cap[num];
	    for(int i = 0; i<num; i++)
	        cin>>cap[i];
	    
	    vector<vector<int>> Edges(num-1);
	    for(int i=1;i < num;i++){
	        int u, v; cin >> u >> v;
	        Edges[i-1].push_back(u);
	        Edges[i-1].push_back(v);
	    }
	    
	    
    	Solution obj;
	    long long ans = obj.minimum_amount(Edges, num, start, cap);
	    cout << ans << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends