// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxBinTreeGCD(vector<vector<int>> arr, int N) {
        // code here
        map<int,vector<int>>m;
        for(int i=0;i<arr.size();i++)
        m[arr[i][0]].push_back(arr[i][1]);
        
        int gc=1;
        int maxi=0;
        
        if(arr.size()==1)
        return 0;
        
        for(auto it:m)
        {
            vector<int>v=it.second;
            
            
            int gc=v[0];
            if(v.size()==1)
            gc=0;
            
            for(int i=1;i<v.size();i++)
            {
                gc=__gcd(v[i],gc);
            }
        
            maxi=max(gc,maxi);
        }
        
        return maxi;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,u,v;
        cin>>N;
        
        vector<vector<int>> arr;
        
        for(int i=0; i<N-1; i++)
        {
            cin>>u>>v;
            vector<int> edge;
            edge.push_back(u);
            edge.push_back(v);
            arr.push_back(edge);
        }

        Solution ob;
        cout << ob.maxBinTreeGCD(arr,N) << endl;
    }
    return 0;
}  // } Driver Code Ends