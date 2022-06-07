class Solution {
public:
    bool canJump(vector<int>& nums) {
        
         int max_reachable_pt = nums.size() - 1;
        
        for(int i = nums.size() - 2 ; i >= 0 ; --i)
            if(nums[i] + i >= max_reachable_pt)
                max_reachable_pt = i;
        return max_reachable_pt <= 0;
        
    }
};