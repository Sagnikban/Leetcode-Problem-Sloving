class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        if(target>nums[nums.size()-1])
        return nums.size();
        
        if(target<nums[0])
        return 0;
        
        
        int l=0,r=nums.size()-1;
        int flag=2;
        while(l<=r)
        {
             int mid=(l+r)/2;
            
             if(nums[mid]==target)
             {
               flag=1;
               return mid;
             }
            if(nums[mid]<target)
            l=mid+1;
            
            if(nums[mid]>target)
            r= mid-1;
             
      }
        vector<int>::iterator it;
        

        return lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        
        return 0;
            
    }
};