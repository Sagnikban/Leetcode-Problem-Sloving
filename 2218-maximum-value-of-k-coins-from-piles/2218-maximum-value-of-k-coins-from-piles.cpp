class Solution {
public:
    int f(int ind,int k,vector<vector<int>> &piles,vector<vector<int>> &dp)
    {
        
        if(ind==piles.size() || k==0)
        return 0;   
        
        if(dp[ind][k]!=-1)
        return dp[ind][k];
        
        int best=f(ind+1,k,piles,dp);
        
        int sum=0;
        
        for(int i=0;i<min(k,(int)piles[ind].size());i++)
        {
            sum+=piles[ind][i];
            best=max(sum+f(ind+1,k-(i+1),piles,dp),best);
        }
        
       
        return dp[ind][k]=best;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<vector<int>>dp(piles.size(),vector<int>(k+1,-1));
        return f(0,k,piles,dp);
    }
};