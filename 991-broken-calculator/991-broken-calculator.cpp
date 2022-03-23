class Solution {
public:
    
    int solve(int startValue,int target,int ans)
    {
        if(target==startValue)
        return ans;
        
        if(target<startValue)
        return solve(startValue,target+1,ans+1);    
        
        if(target%2==1)
        return solve(startValue,target+1,ans+1);
        else
        return solve(startValue,target/2,ans+1);     
    }
    
    int brokenCalc(int startValue, int target) {
       int c=0;
      return solve(startValue,target,c);
    
    }
};