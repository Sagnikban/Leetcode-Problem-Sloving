class Solution {
public:
    int ans=0;
    void solve(vector<int>&nums)
    {
        int c=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            c++;
        }
        
        if(c==nums.size())
        return;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==1)
            {
                nums[i]--;
                ans++;
            }
        }
        int flag=1;
        for(int j=0;j<nums.size();j++)
        {
            if(nums[j]!=0)
            {
                flag=2;
            nums[j]=nums[j]/2;
            }
        }
        
        if(flag==2)
        ans++;
        
        solve(nums);
    }
    int minOperations(vector<int>& nums) {
        solve(nums);
        
        return ans;
    }
};