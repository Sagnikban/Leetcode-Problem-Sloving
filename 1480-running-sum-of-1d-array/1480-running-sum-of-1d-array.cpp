class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
        vector<int> presum(nums.size());
        presum[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        presum[i]=presum[i-1]+nums[i];
        
        return presum;
    }
};