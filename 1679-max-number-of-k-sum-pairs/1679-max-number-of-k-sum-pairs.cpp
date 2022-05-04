class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
       int count =0;
        unordered_map<int,int> mp;
        
        for(int i =0;i<nums.size();i++){
        
            int diff = k - nums[i];  
            if(mp[diff]>0){
                
                count++;               // increase count since we got the pair
                mp[diff]--;            // decrease freq of diff as we used it for our pair 
                
            }
            else{
                mp[nums[i]]++;         // no pair found so put it in hashmap
            }
            
            
        }
        
        return count;
        
        
       /* sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        int ans=0;
        while(i<j)
        {
            if(nums[i]+nums[j]==k)
            {
                ans++;
                i++;
                j--;
            }
            else if(nums[i]+nums[j]>k)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        
        return ans;*/
    }
};