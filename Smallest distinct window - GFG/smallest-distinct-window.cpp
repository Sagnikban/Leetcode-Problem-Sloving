// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here 
         unordered_set<char>s;
         for(int i=0;i<str.size();i++)
         s.insert(str[i]);
         
         
         unordered_map<char,long long>m;
         
         long long min_w_len=INT_MAX;
         long long start_i=0;
         
         for(long long i=0;i<str.size();i++)
         {
             m[str[i]]++;
             
             if(m.size()==s.size())
             {
                while(start_i<i)
                 {
                     if(m[str[start_i]]==1)
                     break;
                     
                     m[str[start_i]]--;
                     
                     start_i++;
                 }
                 
                 
                 
                if(i-start_i+1<min_w_len)
                {
                    min_w_len=i-start_i+1;
                    
                    
                }
                 
                 
             }
             
             
          
             
         }
  
         return min_w_len;
    }
};
// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends