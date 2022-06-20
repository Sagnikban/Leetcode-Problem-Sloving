class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
    long long sum = 0,n=nums.size(),x=0,y=-1,ans=0;
        while(x<n)
        {
            if(y<x-1)
            {
                y=x-1;
                sum=0;
            }  
            while(y+1<n &&(sum+nums[y+1])*(y+1-x+1)<k)
            {
                y++;
                sum+=nums[y];
            } 
            
            int tmp=y-x+1;
            ans+=tmp;
            sum-=nums[x];
            x++;
        }
        
    return ans;
    }
};