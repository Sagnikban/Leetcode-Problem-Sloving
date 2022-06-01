class Solution {
public:
    bool isvalid(int i,int j,int n,int m,vector<vector<char>>& grid)
    {
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j]=='1')
        return true;
        
        return false;
    }
    
   void dfs(int i,int j,int n,int m,vector<vector<char>>& grid)
    {
       grid[i][j]='0';
       
       if( isvalid( i-1, j, n,m,grid))
       dfs(i-1,j,n,m,grid);
       
       if(isvalid(i+1, j,n,m,grid))
       dfs(i+1, j,n,m,grid);     
            
      if(isvalid( i,j+1,n, m,grid))
      dfs(i,j+1,n,m,grid);
       
      if(isvalid( i, j-1,n, m,grid))
      dfs(i,j-1,n, m,grid);   
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
       

        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    ans++;
                    dfs(i,j,grid.size(),grid[0].size(),grid);
                }
            }
        }
        
        return ans;
    }
};