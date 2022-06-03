class Solution {
public:
     
    int dp[100000][3];
    
    int giveAns(vector<int>& nums,int start,int count){
        if(start>=nums.size()){
            if(count==0) return 0;
            return INT_MIN;
        }
        if(dp[start][count]!=-1) return dp[start][count];
        int mod=nums[start]%3;
        int x=nums[start]+giveAns(nums,start+1,(count+mod)%3);
        int y=giveAns(nums,start+1,count);
        return dp[start][count]=max(x,y);
    }
    
    int maxSumDivThree(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return giveAns(nums,0,0);
    }
};