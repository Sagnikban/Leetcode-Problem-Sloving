class Solution {
public:
       long long helper(vector<vector<int>>& obstacleGrid,int i,int j,int z)
    {
        if(i<0 || j<0 ||i>=obstacleGrid.size()||j>=obstacleGrid[0].size())
        return 0;
           
           if(i>=0 && j>=0 && i<obstacleGrid.size() &&j<obstacleGrid[0].size() && obstacleGrid[i][j]==-1 )
        return 0;    
            
        if(obstacleGrid[i][j]==2)
        {
            return z==-1?1:0;
        }
        obstacleGrid[i][j]=-1;
        z--;   
           
    
        long long up=helper( obstacleGrid,i-1,j,z);
        
        long long left=helper(obstacleGrid,i,j-1,z);
           
        long long down=helper(obstacleGrid,i+1,j,z);
            
        long long right=helper(obstacleGrid, i,j+1,z);
           
        obstacleGrid[i][j]=0;
        z++;   
           
        
        return up+left+down+right;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        long long m=grid.size();
        long long n=grid[0].size();
        vector<vector<long long>>dp;
        for(long long i=0;i<m;i++)
        {
            vector<long long>v;
            for(long long j=0;j<n;j++)
             v.push_back(-1); 
            
            dp.push_back(v);
        }
        
        int dest_i,dest_j,start_i,start_j;
        int z=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    dest_i=i;
                    dest_j=j;
                }
                  if(grid[i][j]==1)
                {
                    start_i=i;
                    start_j=j;
                }
                
                if(grid[i][j]==0)
                  z++;  
            }
        }
        
    
         
         return helper(grid,start_i,start_j,z);
        
    }
};