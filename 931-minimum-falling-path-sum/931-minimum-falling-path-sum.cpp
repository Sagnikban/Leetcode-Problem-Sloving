class Solution {
public:
    int dp[101][101];
    int recurse(vector<vector<int>>& triangle,int i,int j,int n)
    {
        if(j<0 || j>=n)
        return 10000;   
        
        if(dp[i][j]!=-1)
        return dp[i][j]; 
        
        if(i==n-1)
        return dp[n-1][j]=triangle[n-1][j];
        
      
        
        
        int down=triangle[i][j]+recurse(triangle,i+1,j,n);
        int down_diag_left=triangle[i][j]+recurse(triangle,i+1,j-1,n);
        int down_diag=triangle[i][j]+recurse(triangle,i+1,j+1,n);
        
        return dp[i][j]=min(down,min(down_diag,down_diag_left));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
         
        int n=matrix.size();
        memset(dp,-1,sizeof(dp));
        int mini=INT_MAX;
        for(int i=0;i<matrix.size();i++)
        {
            
           dp[0][i]=recurse(matrix,0,i,n);
            mini=min(dp[0][i],mini);
        }
        
        return mini;
    }
};