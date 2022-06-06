class Solution {
public:
    int n,m;
     bool isvalid(int i,int j,int n,int m)
    {
        if(i>=0 && i<n && j>=0 && j<m )
        return true;
        
        return false;
    }
    int dfs(int i,int j,vector<vector<int>>& grid)
    {
      if (!(isvalid(i,j,grid.size(),grid[0].size())) || grid[i][j] == 0)
      return 0;
        
        if(grid[i][j]==1)
        {
        grid[i][j]=0;
        return 1+ dfs(i+1,j,grid)+dfs(i,j+1,grid)+dfs(i-1,j,grid)+dfs(i,j-1,grid);
        }
        
        
        return 0;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        n=grid.size();
        m=grid[0].size();
        int ans=0;
         for(int i=0;i<grid.size();i++)
         {
             for(int j=0;j<grid[0].size();j++)
             {
                 if(grid[i][j]==1)
                 ans=max(ans,dfs(i,j,grid));    
             }
         }
        
        return ans;
    
    }
};