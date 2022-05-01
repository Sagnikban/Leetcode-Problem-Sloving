// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
public:	
	void isprime(vector<int>&prime,int n)
	{
	    
	    prime[0]=prime[1]=1;
	    for(int i=2;i*i<=n;i++)
	    {
	        if(prime[i]==0)
	        {
	            for(int j=i*i;j<=n;j+=i)
	            prime[j]=1;
	        }
	    }
	}
	int superPrimes(int n)
	{
	    
	    int c=0;
	    vector<int>prime(n);
	    
	    for(int i=0;i<n;i++)
	    prime.push_back(0);
	    
	    isprime(prime,n);
	    for(int i=2;i<=n;i++)
	   {
           if(prime[i]==0 && prime[i-2]==0)
           c++;
	   } 
	   
	   return c;
	}
};

// { Driver Code Starts.

int main() 
{

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
   		Solution ob;
   		cout << ob.superPrimes(n) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends