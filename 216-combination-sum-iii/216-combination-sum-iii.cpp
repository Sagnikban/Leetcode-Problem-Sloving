class Solution {
public:

    void recurse(int k,int n,vector<int>&res,int sum,vector<vector<int>>&ans)
    {
        if(k==0  && sum==0)
        {
            ans.push_back(res);
            return;
        }
        
        if(k==0 || n==0 || sum==0)
        return;    

        
       
           res.push_back(n);
           recurse(k-1,n-1,res,sum-n,ans);
           res.pop_back();
           recurse(k,n-1,res,sum,ans) ;
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>res;
            vector<vector<int>>ans;
        int sum=n;
        recurse(k,9,res,sum,ans);
        
        return ans;
    }
};