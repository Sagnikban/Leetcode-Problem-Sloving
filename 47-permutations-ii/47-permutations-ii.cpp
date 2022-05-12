class Solution {
public:
    set<vector<int>>s;
    void permutations(vector<int>& nums, int i){
        if(i == nums.size()){
            s.insert(nums);
            return;
        } 
        for(int j = i; j < nums.size(); j++){
            swap(nums[i], nums[j]);
            permutations(nums, i+1);
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        permutations(nums, 0);
        for(auto vec : s) ans.push_back(vec);
        return ans;
    }
};