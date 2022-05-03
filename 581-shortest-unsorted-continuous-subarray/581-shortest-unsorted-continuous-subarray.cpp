class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        vector<int>copy;
        for(int i=0;i<nums.size();i++)
        copy.push_back(nums[i]);
        
        if(nums.size()==1)
        return 0;    
        
        
        
        sort(copy.begin(),copy.end());
        
        if(copy==nums)
        return 0;    
        
        int i=0,j=nums.size()-1;
        while(i<j)
        {
            if(nums[i]==copy[i])
             i++;
            
            if(nums[j]==copy[j])
             j--;
            
            if(nums[i]!=copy[i]&&nums[j]!=copy[j])
            break;    
        }
        
        return j-i+1;
    }
};