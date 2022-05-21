class Solution {
public:
    int recurse(vector<vector<int>> &triangle,vector<vector<int>> &dp,int i,int j,int n)
    {
        if(dp[i][j]!=-1)
        return dp[i][j];
        
       if(i==n-1)
       {
           return triangle[i][j];
       }
        
   
        
        int down=triangle[i][j]+recurse(triangle,dp,i+1,j,n);
        int down_diag=triangle[i][j]+recurse(triangle,dp,i+1,j+1,n);
        
        return dp[i][j]=min(down,down_diag);
        
        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        
         return recurse(triangle,dp,0,0,n);
     
     

    }
};