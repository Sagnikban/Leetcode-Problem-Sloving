class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        
 int count = 0;

    int curr = INT_MIN;

    for(int i = 1;i<nums.size();i++)
    {
       if(nums[i]>=nums[i-1])
           curr = nums[i-1];
        else
        {
            if(curr>nums[i])
            nums[i]=nums[i-1];
            count++;
        }
            
        if(count>=2)
            return false;
    }
    return true;
    }
};