class Solution {
public:
 int fun(vector<int>& nums) {
    int n=nums.size();
    int dp[101]={0};
    dp[1]=nums[0];
    for(int i=2;i<=n;i++){
        dp[i]=max(dp[i-1],nums[i-1]+dp[i-2]);
    }
    return dp[nums.size()];
}
int rob(vector<int>& nums) {
    vector<int>v1,v2;
    if(nums.size()==1)return nums[0];
    
    for(int i=0;i<nums.size()-1;i++)v1.push_back(nums[i]);
    for(int i=1;i<nums.size();i++)v2.push_back(nums[i]);
    return max(fun(v1),fun(v2));
}
};