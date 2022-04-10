class Solution {
public:
    int calPoints(vector<string>& ops) {
             vector<int> nums;
        for(auto &it : ops){
            if(it == "+"){
                nums.push_back(nums.back() + nums[nums.size()-2]);
            }else if(it == "C"){
                nums.pop_back();
            }else if(it == "D"){
                nums.push_back(2*nums.back());
            }else{
                nums.push_back(stoi(it));
            }
        }
        return accumulate(nums.begin(),nums.end(),0);
    }
};