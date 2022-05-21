class Solution {
public:
    int recurse(int i,int j1,int j2,vector<vector<int>>& grid,int dp[200][200][200],int n,int m)
    {
        if(j1<0 ||j1>=m|| j2<0|| j2>=m)
        return -300;
        
        if(dp[i][j1][j2]!=-1)
        return dp[i][j1][j2];
        
        if(i==n-1)
        {
            if(j1==j2)
            return dp[i][j1][j2]=grid[i][j1];
            else
            return dp[i][j1][j2]=grid[i][j1]+grid[i][j2];    
        }    
        int maxi=INT_MIN;
        
   //Checking all nine possibilities and taking the maximum value   
   for(int dj1=-1;dj1<=1;dj1++)
    {
      for(int dj2=-1;dj2<=1;dj2++)
        {
           if(j1==j2)
            maxi=max(grid[i][j1]+recurse(i+1,j1+dj1,j2+dj2,grid,dp,n,m),maxi);
                else
            maxi=max(maxi,grid[i][j1]+grid[i][j2]+recurse(i+1,j1+dj1,j2+dj2,grid,dp,n,m));   
            }
        }
                     
          return dp[i][j1][j2]=maxi;           
                         
                         
    }
    int cherryPickup(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        int dp[200][200][200];
        for(int i=0;i<200;i++)
        {
            for(int j=0;j<200;j++)
            {
                for(int k=0;k<200;k++)
                {
                    dp[i][j][k]=-1;
                }
            }
        }  
        return recurse(0,0,m-1,grid,dp,n,m);
    }
};