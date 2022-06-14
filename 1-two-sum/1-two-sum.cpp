class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n=nums.size();
        vector<int> ans;
        map<int,int> m;
        
        for(int i=0;i<n;i++) {
            m[nums[i]] = i;
        }
        
        for(int i=0;i<n;i++) 
        {
            int tar = target - nums[i];
            if(m[tar] && m[tar] != i) {
                ans.push_back(i);
                ans.push_back(m[tar]);
                break;
            }
        }
        return ans;
    }
};