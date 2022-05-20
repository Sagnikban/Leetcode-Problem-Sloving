// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int findTime(string S1, string S2) {
        // code here
        map<char,int>m;
        for(int i=0;i<S1.length();i++)
        m[S1[i]]=i;
        
        int sum=0;
        sum=m[S2[0]];
      
        for(int j=1;j<S2.length();j++)
        {
            sum+=(abs(m[S2[j]]-m[S2[j-1]]));
        }
        
        return sum;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S1,S2;
        cin>>S1;
        cin>>S2;

        Solution ob;
        cout<<ob.findTime(S1,S2)<<endl;
    }
    return 0;
}  // } Driver Code Ends