class Solution {
public:
    int specialArray(vector<int>& nums) {
 
        sort(nums.begin(),nums.end());
        for(int i=0;i<=*max_element(nums.begin(),nums.end());i++)
        {
            auto it=lower_bound(nums.begin(),nums.end(),i);
            int x=it-nums.begin();
            
            if(nums.size()-x==i)
            return i;    
        }
        return -1;
        
    }
};