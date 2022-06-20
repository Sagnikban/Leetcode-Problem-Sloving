class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int c=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>=k)
            c++;    
        }
        if(c==nums.size())
        return 0;    
        long long prod= 1, count = 0;
        int i=0;
        for(int j=0; j<nums.size(); j++)
        {
            prod*=nums[j];
            while(prod>=k)
            {
                prod/=nums[i];
                i++;
            }
            count+=(j-i+1);
        }
        return count;
    }
    
};