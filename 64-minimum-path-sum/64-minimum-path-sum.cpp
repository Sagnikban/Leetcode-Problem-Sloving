class Solution
{
public:
    int cost(int i, int j, vector<vector<int> > &grid, vector<vector<int> > &dp)
    {
        if (i < 0 || j < 0)
            return INT_MAX;

        if (i == 0 && j == 0)
            return grid[0][0];

        if (dp[i][j] != -1)
            return dp[i][j];

        int up = cost(i - 1, j, grid, dp);
        int left = cost(i, j - 1, grid, dp);

        return dp[i][j] = grid[i][j] + min(up, left);
    }

    int minPathSum(vector<vector<int> > &grid)
    {
        int r = grid.size(), c = grid[0].size();
        vector<vector<int> > dp(r, vector<int>(c, -1));
        return cost(r - 1, c - 1, grid, dp);
    }
};