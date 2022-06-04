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
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return recurse(m-1,n-1,word1,word2,dp);
    }
};