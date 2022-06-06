// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long countKdivPairs(int A[], int n, int K)
    {
        //code here
        unordered_map<long long,long long>m;
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            int x=A[i]%K;
            if (x == 0 && m.find(0) != m.end()) 
            ans += m[0];
            if(m.find(K-x)!=m.end())
            ans+=m[K-x];
            m[x]++;
        }
        return ans;
        
        
        
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
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int k;
		cin >> k;

        Solution ob;
		cout << ob. countKdivPairs(a, n , k) << "\n";



	}


	return 0;
}
  // } Driver Code Ends