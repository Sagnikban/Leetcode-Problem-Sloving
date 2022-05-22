// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    string findAndReplace(string S ,int Q, int index[], string sources[], string targets[]) {
        // code here
       string res = "";
        int n = S.size();
        while(Q--){
            string source = sources[Q];
            int ss = source.size();
            int idx = index[Q];
            string tar = targets[Q];
            int i = idx;
            string temp = S.substr(idx, ss);
            if(temp == source){
                if(i == 0){
                    res = tar + S.substr(idx+ss);
                    S = res;
                }
                else if(i == n-1){
                    S.pop_back();
                    temp = S + tar;
                    res = temp;
                    S = res;
                }
                else{
                    //midle char deletion
                    string fHalf = S.substr(0, i);
                    int secondIdx = i + ss;
                    string sHalf = S.substr(secondIdx);
                    temp = fHalf + tar +  sHalf;
                    res = temp;
                    S = res;
                }
            }
        }
        return res.size() == 0 ? S: res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        
        int Q;
        cin>>Q;
        int index[Q];
        string sources[Q], targets[Q];
        
        for(int i=0; i<Q; i++)
            cin>>index[i];
        for(int i=0; i<Q; i++)
            cin>>sources[i];
        for(int i=0; i<Q; i++)
            cin>>targets[i];

        Solution ob;
        cout<<ob.findAndReplace(S,Q,index,sources,targets)<<endl;
    }
    return 0;
}  // } Driver Code Ends