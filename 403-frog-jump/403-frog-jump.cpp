class Solution {
public:
    bool getAnsMemo(long long val, long long jump, vector<int>& stones, vector<vector<long long>>& dp){
        auto it = find(stones.begin(), stones.end(), val);
        if(it==stones.end()){
            return false;
        }
        
        long long i = it-stones.begin();
        if(val==stones[stones.size()-1]){
            return true;
        }
        
        if(dp[i][jump]!=-1){
            return dp[i][jump];
        }
        
        bool noNewJump = false;
        if(jump!=0)
            noNewJump = getAnsMemo(val+jump, jump, stones, dp);
        
        bool oneLessJump = false;
        if(jump!=1)
            oneLessJump = getAnsMemo(val+jump-1, jump-1, stones, dp);
        
        bool oneMoreJump = getAnsMemo(val + jump+1, jump+1, stones, dp);
        bool result = noNewJump || oneLessJump || oneMoreJump;
        
        if(result){
            dp[i][jump]=1;
        }
        else{
            dp[i][jump]=0;
        }
        
        return result;
    }
    
    bool canCross(vector<int>& stones) {
         long long n = stones.size();
        vector<vector<long long>> dp (n, vector<long long>(n+1, -1));
        
        
        if(stones[1]-stones[0]!=1){
            return false;
        }
        
        return getAnsMemo(stones[1], 1, stones, dp);
    }
};