// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

int fun(vector<vector<int>>& mat,int i,int j,int n,int m,int prev,vector<vector<int>>&dp)
{
   if(i<0 || j<0 || i>n || j>m || prev>=mat[i][j] ) return 0;
   
   int max1=0;
   if(dp[i][j]!=-1) 
   return dp[i][j];
   if(i+1<n)
   max1=max(max1,1+fun(mat,i+1,j,n,m,mat[i][j],dp));
   if(i-1>=0) 
   max1=max(max1,1+fun(mat,i-1,j,n,m,mat[i][j],dp));
   if(j+1<m)  
   max1=max(max1,1+fun(mat,i,j+1,n,m,mat[i][j],dp));
   if(j-1>=0)
   max1=max(max1,1+fun(mat,i,j-1,n,m,mat[i][j],dp));
      
      
    return dp[i][j]=max1;
}
   int longestIncreasingPath(vector<vector<int>>& mat) {
       int n=mat.size();
       int m=mat[0].size();
       int max2=0;
       vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               max2=max(max2,fun(mat,i,j,n,m,0,dp));
           }
       }
       return max2;
   }

 
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>matrix(n, vector<int>(m, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)cin >> matrix[i][j];
		Solution obj;
		int ans = obj.longestIncreasingPath(matrix);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends