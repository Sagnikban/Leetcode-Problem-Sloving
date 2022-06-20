class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
      
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
           
           auto it=lower_bound(grid[i].rbegin(),grid[i].rend(),0); 
           int x=it-grid[i].rbegin();
           ans+=x; 
            
        }
        return ans;
    }
};