class Solution {
public:

    int minDifficulty(vector<int>& job, int d) {
        
        int n=job.size();
        if(d>n)
        return -1;
        
        int dp[d][n];
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            maxi=max(job[i],maxi);
            dp[0][i]=maxi;
        }  
        
        for(int i=1;i<d;i++)
        {
            for(int j=i;j<n;j++)
            {
                int mni=dp[i-1][j-1]+job[j];
                int mxi=job[j];
                
                for(int k=j;k>=i;k--)
                {
                    mxi=max(mxi,job[k]);
                    mni=min(mni,dp[i-1][k-1]+mxi);
                }
                dp[i][j]=mni;
            }
        }
        return dp[d-1][n-1];
    }
};
