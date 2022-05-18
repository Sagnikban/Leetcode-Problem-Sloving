// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
   vector<string>res;
   void helper(string S,int index,int l,string ans)
   {
       if(index>=l)
       {
           res.push_back(ans);
           return;
       }
       ans.push_back(S[index]);
       helper(S,index+1,l,ans);
       ans.pop_back();
       
       if(index!=S.length()-1)
       {
       ans.push_back(S[index]);
       ans+=" ";
       helper(S,index+1,l,ans);
       ans.pop_back();
       ans.pop_back();
       }
       
   }
    vector<string> permutation(string S){
        // Code Here
        string a="";
        helper(S,0,S.length(),a);
        sort(res.begin(),res.end());
        return res;
    }
};

// { Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}
  // } Driver Code Ends