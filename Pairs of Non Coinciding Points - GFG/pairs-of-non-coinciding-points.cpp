// { Driver Code Starts

#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
    int numOfPairs(int X[], int Y[], int N) {
        // code here
        map<int,int>mx,my;
        map<pair<int,int>,int>mp;
        int cnt=0;
        for(int i=0;i<N;i++)
        {
            int x=X[i],y=Y[i];
            cnt+=mx[x]+my[y]-2*mp[{x,y}];
            mp[{x,y}]++;
            mx[x]++;
            my[y]++;
            
        }
        return cnt;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        int X[N], Y[N];
        
        for(int i=0; i<N; i++)
            cin>>X[i];
        for(int i=0; i<N; i++)
            cin>>Y[i];

        Solution ob;
        cout << ob.numOfPairs(X,Y,N) << endl;
    }
    return 0;
}  // } Driver Code Ends