// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int a[], int n)  
	{  
	    // Your code goes here
	    int dp[n];
	    dp[0]=a[0];
	    for(int i=1;i<n;i++)
	    {
	        int x=i-1;
	        int maxi=0;
	        for(int j=0;j<i;j++)
	        {
	          if(a[j]<a[i])
	          {
	              maxi=max(maxi,dp[j]);
	          }
	 
	        }
	        
	        dp[i]=maxi+a[i];
	    }

	    return *max_element(dp,dp+n);
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends