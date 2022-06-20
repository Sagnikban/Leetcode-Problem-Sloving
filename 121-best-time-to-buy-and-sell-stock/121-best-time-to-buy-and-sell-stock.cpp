class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxi[n];
        int m=prices[n-1];
        maxi[n-1]=prices[n-1];
        for(int i=n-2;i>=0;i--)
        {
            if(prices[i]>m)
            m=prices[i];
            
            maxi[i]=m;
        }
        int ans=INT_MIN;
        for(int i=0;i<n-1;i++)
        {
           ans=max(ans,maxi[i+1]-prices[i]);
        }
        if(ans<=0)
        return 0;    
        return ans;
    }
};