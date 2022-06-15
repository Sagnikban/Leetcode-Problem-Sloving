class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       map<int,int>m;
        vector<int>sum;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(target-nums[i])!=m.end())
            {
                sum.push_back(m[target-nums[i]]+1);
                sum.push_back(i+1);
                break;
            }
            m[nums[i]]=i;
        }
        
        return sum;
    }
};