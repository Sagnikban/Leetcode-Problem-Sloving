// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
 
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
         if(A[0][0]==0  ||  A[X][Y]==0)return -1;
       
       A[0][0]=0;
       queue<pair<pair<int,int>,int>>q;
       q.push({{0,0},0});
       
       while(!q.empty())
       {
            int i= q.front().first.first;
            int j= q.front().first.second;
            int c= q.front().second;
            if(i==X && j==Y)return c;
            
            q.pop();
            
            if(j-1>=0)
           {
               if(A[i][j-1]==1  )
             {
               A[i][j-1]=0;
               q.push({{i,j-1},c+1});
               
             }
            }
           
       if(i-1>=0)
       {
           if(A[i-1][j]==1 )
           {
               A[i-1][j]=0;
               q.push({{i-1,j},c+1});
              
           }
       }
       
       if(i+1<N)
       {
           if(A[i+1][j]==1 )
           {
               A[i+1][j]=0;
               q.push({{i+1,j},c+1});
               
           }
       }
       
       if(j+1<M)
       {
          if(A[i][j+1]==1 )
           {
               A[i][j+1]=0;
               q.push({{i,j+1},c+1});
               
           } 
       }
            
       
   }
   
   return -1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}  // } Driver Code Ends