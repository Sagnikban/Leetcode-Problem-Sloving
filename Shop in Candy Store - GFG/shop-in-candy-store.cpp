// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        sort(candies,candies+N);
        
        int i=0,j=N-1;
        int ans_min=0;
        
        while(i<=j)
        {
            
            ans_min+=candies[i];
            i++;
            j-=K;
        }
        
        sort(candies,candies+N,greater<int>());
        
          i=0,j=N-1;
        int ans_max=0;
        
        while(i<=j)
        {
            
            ans_max+=candies[i];
            i++;
            j-=K;
        }
        
        vector<int>res;
        res.push_back(ans_min);
        res.push_back(ans_max);
        
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}  // } Driver Code Ends