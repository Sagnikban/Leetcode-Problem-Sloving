class Solution {
public:
    vector<vector<int>>ans;
    void recurse(int k,int n,vector<int>&res,int sum)
    {
        if(k==0  && sum==0)
        {
            ans.push_back(res);
            return;
        }
        
        if(k==0 || n==0 || sum==0)
        return;    

        
          if(find(res.begin(),res.end(),n)==res.end())
          {
           res.push_back(n);
           recurse(k-1,n-1,res,sum-n);
           res.pop_back();
           recurse(k,n-1,res,sum) ;
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>res;
        int sum=n;
        recurse(k,9,res,sum);
        
        return ans;
    }
};