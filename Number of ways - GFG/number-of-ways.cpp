// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long int arrangeTiles(int n){
        // code here
    long long int dp[n+1];
    dp[0] = 0;
 
    // Fill the table from d[1] to dp[n]
    for (long long int i=1; i<=n; i++)
    {
        // Base cases
        if (i >= 1 && i <= 3)
            dp[i] = 1;
        else if (i==4)
            dp[i] = 2 ;
 
        else
            // dp(i-1) : Place first tile horizontally
            // dp(n-4) : Place first tile vertically
            //         which means 3 more tiles have
            //         to be placed vertically.
            dp[i] = dp[i-1] + dp[i-4];
    }
 
    return dp[n];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.arrangeTiles(N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends