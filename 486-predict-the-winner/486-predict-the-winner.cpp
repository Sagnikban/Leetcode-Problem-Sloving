class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
          int dp[nums.size()][nums.size()];
        for (int s = nums.size(); s >= 0; s--) {
            for (int e = s; e < nums.size(); e++) {
                if (s == e) {
                    dp[s][e] = nums[s];
                } else {
                    int a = nums[s] - dp[s + 1][e];
                    int b = nums[e] - dp[s][e - 1];
                    dp[s][e] = max(a, b);
                }
            }
        }
        return dp[0][nums.size() - 1] >= 0;
    }
};