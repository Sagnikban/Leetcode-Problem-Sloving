class Solution {
public:
    int recurse(vector<vector<int>> &triangle,vector<vector<int>> &dp,int i,int j,int n)
    {
        if(dp[i][j]!=-1)
        return dp[i][j];
        
       if(i==n-1)
       {
           return dp[n-1][j]=triangle[i][j];
       }

        
        int down=triangle[i][j]+recurse(triangle,dp,i+1,j,n);
        int down_diag=triangle[i][j]+recurse(triangle,dp,i+1,j+1,n);
        
        return dp[i][j]=min(down,down_diag);
        
        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                if(i==n-1)
                dp[n-1][j]=triangle[i][j];
                else
                {
                     
                  int down=triangle[i][j]+dp[i+1][j];
                  int down_diag=triangle[i][j]+dp[i+1][j+1];
                  dp[i][j]=min(down,down_diag);
                }
                    
                    
            }
        }
         return dp[0][0];
     
     

    }
};