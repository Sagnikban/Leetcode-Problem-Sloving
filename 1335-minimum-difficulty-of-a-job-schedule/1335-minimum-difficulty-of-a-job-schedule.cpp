class Solution {
public:
   int maximum(long long int a,long long int b){
        if(a>b) return a;
        return b;
    }
    int minimum(long long int a,long long int b){
        if(a>b) return b;
        return a;
    }
    long long int solve(int i,int c,int d,vector<int>& jobs,vector<vector<long long int>>& dp){
        
        if(d-1==c && i==jobs.size()) return 0;
        if(i==jobs.size()) return INT_MAX;
        if(dp[i][c]!=-1) return dp[i][c];
        long long int max1=jobs[i],min1=INT_MAX;
        if(d-1==c){
            return dp[i][c]=maximum(solve(i+1,c,d,jobs,dp),jobs[i]);
        }
        for(int k=i;k<jobs.size()-1;k++){
            max1=maximum(max1,jobs[k]);
            min1=minimum(min1,solve(k+1,c+1,d,jobs,dp)+max1);
           // cout<<min1<<" "<<c<<"    ";
        }
        return dp[i][c]=min1;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        vector<vector<long long int>> dp(jobDifficulty.size()+1,vector<long long int>(d+1,-1));
       long long int y=solve(0,0,d,jobDifficulty,dp);
        if(y>=INT_MAX) return -1;
        return y;
    }
};
