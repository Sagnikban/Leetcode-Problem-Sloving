class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
      
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
           reverse(grid[i].begin(),grid[i].end()); 
           auto it=lower_bound(grid[i].begin(),grid[i].end(),0); 
           int x=it-grid[i].begin();
           ans+=x; 
            
        }
        return ans;
    }
};