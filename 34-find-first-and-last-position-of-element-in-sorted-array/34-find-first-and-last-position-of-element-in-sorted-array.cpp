class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0,h=nums.size()-1;
        int ans=INT_MAX;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            
            if(nums[mid]==target)
            {
                ans=min(ans,mid);
                h=mid-1;
            }
            else
            if(nums[mid]>target)
            h=mid-1;
            else
            if(nums[mid]<target)
            {
                l=mid+1;
            }
        }
   
        l=0,h=nums.size()-1;
        int ans1=INT_MIN;
         while(l<=h)
        {
            int mid=l+(h-l)/2;
            
            if(nums[mid]==target)
            {
                ans1=max(ans,mid);
                l=mid+1;
            }
            else
            if(nums[mid]>target)
            h=mid-1;
            else
            if(nums[mid]<target)
            {
                l=mid+1;
            }
        }
        

        vector<int>res;
        if(ans1==INT_MIN)
        {
            res.push_back(-1);
            res.push_back(-1);
            return res;
            
        }
        
        res.push_back(ans);
        res.push_back(ans1);
        return res;
            
            
    }
};