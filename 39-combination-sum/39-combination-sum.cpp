class Solution {
public:
    
    
    void helper(vector<int>& candidates,int target, vector<vector<int>>&ans, vector<int>res, int n)
    {
        if(n<0)
        {
            if(target==0)
            {
                ans.push_back(res);
                
            }
            return;
        }  
        
        
        if(candidates[n]<=target)
        {res.push_back(candidates[n]);
         helper(candidates,target-candidates[n],ans,res,n);
         res.pop_back();
        }
        
        helper(candidates,target,ans,res,n-1);
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>>ans;
        vector<int>res;
        helper(candidates,target,ans,res,candidates.size()-1);
        
        return ans;
    }
};