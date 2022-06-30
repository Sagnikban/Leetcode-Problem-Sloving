#define ll long long int
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        ll prefix[nums.size()];
        ll suffix[nums.size()];
        prefix[0]=nums[0];
        suffix[nums.size()-1]=nums[nums.size()-1];
        for(ll i=1;i<nums.size();i++)
        prefix[i]=prefix[i-1]+nums[i];
        
        for(ll j=nums.size()-2;j>=0;j--)
        suffix[j]=suffix[j+1]+nums[j];
        
        ll  mini=INT_MAX;
        
        for(ll i=0;i<nums.size();i++)
        {
            ll s=suffix[i]-(nums.size()-i)*nums[i];
            ll p=(i+1)*nums[i]-prefix[i];
            //cout<<s<<" "<<p<<endl;
            mini=min(mini,s+p);
        }
    
        
        return mini;
    }
};