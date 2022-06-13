class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int end=0,start=0;
        map<int,int>m;
        int wsum=0,sum=0;
        int ans=INT_MIN;
        
        while(end<nums.size())
        {
            wsum+=nums[end];
            
            while(m.find(nums[end])!=m.end())
            {
                wsum-=nums[start];
                m.erase(nums[start]);
                start++;
            }
            
            ans=max(ans,wsum);
            m[nums[end]]=end;
            end++;
        }
        
        return ans;
        
    }
};