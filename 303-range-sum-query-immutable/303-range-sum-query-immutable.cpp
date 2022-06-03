class NumArray {
public:
    vector<int>dp;
    NumArray(vector<int>& nums) {
        dp=nums;
        
        for(int i=1;i<nums.size();i++)
        dp[i]=dp[i-1]+nums[i];    
        
         
    }
    
    int sumRange(int left, int right) {
        
        int sum_left=0;
        if(left!=0)
        sum_left=dp[left-1];
 
        int sum_right=dp[right];
        
        return -sum_left+sum_right;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */