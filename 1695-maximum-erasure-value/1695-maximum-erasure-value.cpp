class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
       int sum=0,ans=0,n=nums.size(),j=0;
        unordered_set<int> s;
        for(int i=0;i<n;i++) {
            if(s.find(nums[i])==s.end()) {
                s.insert(nums[i]);
                sum+=nums[i];
                ans = max(ans,sum);
            }
            else {
                while(s.find(nums[i])!=s.end())
                {
                    s.erase(nums[j]);
                    sum-=nums[j];
                    j++;
                }
                s.insert(nums[i]);
                sum+=nums[i];
                ans = max(ans,sum);
            }
            
        }
        ans = max(ans,sum);
        return ans;
    }
};