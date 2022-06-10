class Solution {
public:
    void dfs(vector<vector<int>> &heights, int i, int j, int &m, int &n, long prev, vector<vector<bool>> &ocean)
{
    if(i >= m || i < 0 || j < 0 || j >= n || heights[i][j] < prev || ocean[i][j])
        return;
    
    ocean[i][j] = true;
    dfs(heights, i + 1, j, m, n, heights[i][j], ocean);
    dfs(heights, i - 1, j, m, n, heights[i][j], ocean);
    dfs(heights, i, j + 1, m, n, heights[i][j], ocean);
    dfs(heights, i, j - 1, m, n, heights[i][j], ocean);
}
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
         int m = heights.size(), n = heights[0].size();
    vector<vector<bool>> pacific(m, vector<bool> (n, false)), atlantic = pacific;
    
    for(int i = 0; i < m; i++)
        dfs(heights, i, 0, m, n, LONG_MIN, pacific);
    
    for(int i = 0; i < n; i++)
        dfs(heights, 0, i, m, n, LONG_MIN, pacific);
    
    for(int i = 0; i < m; i++)
        dfs(heights, i, n - 1, m, n, LONG_MIN, atlantic);
    
    for(int i = 0; i < n; i++)
        dfs(heights, m - 1, i, m, n, LONG_MIN, atlantic);
    
    vector<vector<int>> ans;
    for(int i = 0; i < m; i++)
    {
    for(int j = 0; j < n; j++)
    if(pacific[i][j] && atlantic[i][j])
    ans.push_back({i, j});
    }
    return ans;
    }
};