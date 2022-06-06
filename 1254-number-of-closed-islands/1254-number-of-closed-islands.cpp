class Solution {
public:
     bool isvalid(int i,int j,int n,int m)
    {
        if(i>=0 && i<n && j>=0 && j<m )
        return true;
        
        return false;
    }
    void dfs(int i,int j,int n,int m,vector<vector<int>>& grid)
    {
        if(isvalid(i,j,n,m)&& grid[i][j]==0)
        grid[i][j]=1;
        else
        return;    
        
        dfs(i+1,j,n,m,grid);
        dfs(i,j+1,n,m,grid);
        dfs(i,j-1,n,m,grid);
        dfs(i-1,j,n,m,grid);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // boundary DFS
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i*j == 0 || i == n-1 || j==m-1){
                    if(grid[i][j] == 0){
                        dfs(i, j, n, m, grid);
                    }
                }
            }
        }
        
        // call DFS in whole grid
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 0){
                    ans++;
                    dfs(i, j, n, m, grid);
                }
            }
        }
        
        return ans;
    }
};