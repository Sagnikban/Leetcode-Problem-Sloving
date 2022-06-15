class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
       map<int, int> mpp;
        int sum = 0, ans = 0, j = 0, i=0;
        while(i<nums.size())
        {
            if(mpp[nums[i]])
            {
                while(mpp[nums[i]])
                {
                    mpp[nums[j]]--;
                    sum-=nums[j];
                    j++;
                }
                // ans = max(ans, sum);
            }
            else
            {
                
                sum += nums[i];
                ans = max(ans, sum);
                mpp[nums[i]]++;
                i++;
            }
        }
        
        return ans;
        
    }
};