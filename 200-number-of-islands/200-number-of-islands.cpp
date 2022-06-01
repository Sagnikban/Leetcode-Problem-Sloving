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
       
       if( i-1>=0 && i-1<n && j>=0 && j<m && grid[i-1][j]=='1')
       dfs(i-1,j,n,m,grid);
       
       if(i+1>=0 && i+1<n && j>=0 && j<m && grid[i+1][j]=='1')
       dfs(i+1, j,n,m,grid);     
            
      if(i>=0 && i<n && j+1>=0 && j+1<m && grid[i][j+1]=='1')
      dfs(i,j+1,n,m,grid);
       
      if(i>=0 && i<n && j-1>=0 && j-1<m && grid[i][j-1]=='1')
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