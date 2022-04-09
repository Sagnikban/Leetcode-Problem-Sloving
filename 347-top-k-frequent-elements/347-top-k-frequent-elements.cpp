class Solution {
public:
    static bool comp(const pair<int,int>&a,const pair<int,int>&b)
    {
        return a.second>b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<pair<int,int>>v;
        unordered_map<int,int>m;
        
        for(int i=0;i<nums.size();i++)
        m[nums[i]]++;
        
        for(auto it =m.begin();it!=m.end();it++)
        v.push_back({(*it).first,(*it).second});
        
        sort(v.begin(),v.end(),comp);
        
        nums.clear();
        
        for(int i=0;i<k;i++)
        nums.push_back(v[i].first);
        
        
        return nums;
    }
};