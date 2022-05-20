class Solution {
public:
   long long helper(vector<vector<int>>& obstacleGrid,vector<vector<long long>>& dp,long long i,long long j)
    {
        if(i>=0 && j>=0 && obstacleGrid[i][j]==1 )
        return dp[i][j]=0;    
            
        if(i==0 && j==0)
        return dp[i][j]=1;
        
        if(i<0 || j<0)
        return 0;
        
        if(dp[i][j]!=-1)
        return dp[i][j];
        
    
        long long up=helper( obstacleGrid,dp,i-1,j);
        
        long long left=helper(obstacleGrid, dp,i,j-1);
        
        return dp[i][j]=up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      
        long long m=obstacleGrid.size();
        long long n=obstacleGrid[0].size();
        vector<vector<long long>>dp;
        for(long long i=0;i<m;i++)
        {
            vector<long long>v;
            for(long long j=0;j<n;j++)
             v.push_back(-1); 
            
            dp.push_back(v);
        }
         helper(obstacleGrid,dp,m-1,n-1);
        return dp[m-1][n-1]==-1?0:dp[m-1][n-1];
        
        
    }
};