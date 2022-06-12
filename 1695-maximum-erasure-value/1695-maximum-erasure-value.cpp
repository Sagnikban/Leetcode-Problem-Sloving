class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        set<int>s;
        int i=0;
        int j=0;
        int sum=0;
        int ans=0;
        while(i<nums.size() && j<nums.size()){
            if(s.find(nums[j])==s.end()){
                sum+=nums[j];
                ans = max(ans,sum);
                s.insert(nums[j]);
                j++;
            }
            else{
                sum-=nums[i];
                s.erase(nums[i]);
                i++;
            }
        }
        return ans;
    }
};