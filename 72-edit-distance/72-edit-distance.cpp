class Solution {
public:
    int recurse(int i,int j,string word1,string word2, vector<vector<int>>&dp)
    {
        if(i<0)
         return j+1;     
            
        if(j<0)
        return i+1;
        
        
        if(dp[i][j]!=-1)
        return dp[i][j];
        
        if(word1[i]!=word2[j])
        return dp[i][j]=1+min({recurse(i-1,j-1,word1,word2,dp),recurse(i-1,j,word1,word2,dp),recurse(i,j-1,word1,word2,dp)});
        
        return dp[i][j]=recurse(i-1,j-1,word1,word2,dp);
        
    }
    int minDistance(string word1, string word2) {
      
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<=m;i++)
        dp[i][0]=i;
        
        for(int i=1;i<=n;i++)
        dp[0][i]=i;
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(word1[i-1]==word2[j-1])
                dp[i][j]=dp[i-1][j-1];
                else
                dp[i][j]=1+min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});    
            }
        }
        
        return dp[m][n];
    }
};