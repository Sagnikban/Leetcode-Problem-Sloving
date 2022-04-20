class Solution {
public:
    vector<vector<int>>v;
    set<vector<int>>s;
    void helper(vector<int>nums,int length,vector<int>ans)
    {
        if(length<0)
        {
            if(ans.size()>=2)
            {
              reverse(ans.begin(),ans.end());
              s.insert(ans);
            }
            return;
        }
        if(ans.size()==0)
        {
        ans.push_back(nums[length]);
        helper(nums,length-1,ans);
        ans.pop_back();
        }
        else
        if(nums[length]<=ans[ans.size()-1] )
        {
        ans.push_back(nums[length]);
        helper(nums,length-1,ans);
        ans.pop_back();
        }
        
        helper(nums,length-1,ans);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        vector<int>ans;
        helper(nums,nums.size()-1,ans);
         for(auto it:s)
         v.push_back(it);    
        return v;
    }
};