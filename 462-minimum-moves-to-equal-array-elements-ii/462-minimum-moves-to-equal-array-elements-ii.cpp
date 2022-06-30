#define ll long long int
class Solution {
public:
    int minMoves2(vector<int>& nums) 
    {
        ll n=nums.size();
        sort(nums.begin(),nums.end());
        ll prefix[nums.size()];
        ll suffix[nums.size()];
        prefix[0]=nums[0];
        suffix[n-1]=nums[n-1];
        for(ll i=1;i<n;i++)
        prefix[i]=prefix[i-1]+nums[i];
        
        for(ll j=n-2;j>=0;j--)
        suffix[j]=suffix[j+1]+nums[j];
        
        ll  mini=INT_MAX;
        
        for(ll i=0;i<n;i++)
        {
            ll s=suffix[i]-(n-i)*nums[i];
            ll p=(i+1)*nums[i]-prefix[i];
            //cout<<s<<" "<<p<<endl;
            mini=min(mini,s+p);
        }
    
        
        return mini;
    }
};