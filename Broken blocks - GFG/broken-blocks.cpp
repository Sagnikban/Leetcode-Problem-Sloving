// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
int solve(int i, int j, vector<vector<int>>&mat, int row, int col,vector<vector<int>>&dp){
   if(i < 0 || j < 0 || i >= row || j >= col || mat[i][j] == -1){
       return 0;
   }
   if(dp[i][j] != -1)
   return dp[i][j];
   int down = mat[i][j] + solve(i+1, j, mat, row, col, dp);
   int left = mat[i][j] + solve(i+1, j-1, mat, row, col, dp);
   int right = mat[i][j] + solve(i+1, j+1, mat, row, col, dp);
   return dp[i][j] = max(down, max(left, right));
}
int MaxGold(vector<vector<int>>&matrix){
   int m = matrix.size();
   int n = matrix[0].size();
   int ans, mx = INT_MIN;
   for(int i = 0; i < n; i++){
       vector<vector<int>>dp(m, vector<int>(n, -1));
       if(matrix[0][i] != -1){
           int ans = solve(0, i, matrix, m, n, dp);
           mx = max(mx, ans);
       }
   }
   if(mx == INT_MIN)
   return 0;
   return mx;
}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int m, n;
		cin >> m >> n;
		vector<vector<int>>matrix(m, vector<int>(n, 0));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)
				cin >> matrix[i][j];
		}
		Solution obj;
		int ans = obj.MaxGold(matrix);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends