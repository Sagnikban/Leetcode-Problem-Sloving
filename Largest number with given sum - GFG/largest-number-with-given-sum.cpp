// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return Largest Number

class Solution
{
    public:
    //Function to return the largest possible number of n digits
    //with sum equal to given sum.
    string largestNumber(int n, int sum)
    {
        // Your code here
        if(n*9<sum )
        return "-1";
        
        string ans="";
        int s=0;
        for(int i=1;i<=n;i++)
        {
            if(s==sum)
            ans+="0";
            else
            {
                if(s+9<=sum)
                {
                ans+="9";
                s+=9;
                }
                else
                {
                  
                     ans+=to_string(sum-s);
                     s+=sum-s;
                }
               
            }
            
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin>>t;

	while(t--)
	{
	    //taking n and sum
		int n,sum;
		cin>>n>>sum;
		
        Solution obj;
        //function call
		cout<<obj.largestNumber(n, sum)<<endl;
	}
	return 0;
}  // } Driver Code Ends