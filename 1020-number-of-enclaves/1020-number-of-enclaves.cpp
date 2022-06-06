class Solution {
public:
     bool isvalid(int i,int j,int n,int m)
    {
        if(i>=0 && i<n && j>=0 && j<m )
        return true;
        
        return false;
    }
   int dfs(int i,int j,int n,int m,vector<vector<int>>& grid)
    {
        
        if(isvalid(i,j,n,m)&& grid[i][j]==1)
        {
          grid[i][j]=0;
        
          return 1+dfs(i+1,j,n,m,grid)+ dfs(i,j+1,n,m,grid)+
                 dfs(i,j-1,n,m,grid)+dfs(i-1,j,n,m,grid);
        }
       
       return 0;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i*j==0 ||i==m-1||j==n-1)
                dfs(i,j,m,n,grid);    
            }
        }
        int res=0;
         for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                res+=dfs(i,j,m,n,grid);    
            }
        }
        
        return res; 
    }
};