class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        if(target>nums[nums.size()-1])
        return nums.size();
        
        if(target<nums[0])
        return 0;
        
     
        return lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        
        return 0;
            
    }
};