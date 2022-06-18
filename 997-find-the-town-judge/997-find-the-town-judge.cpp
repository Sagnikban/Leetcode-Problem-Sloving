class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
      
        map<int,int>m;
        for(int i=0;i<trust.size();i++)
        {
            m[trust[i][1]]++;
        }
        
        int c=0;
        for(int i=1;i<=n;i++)
        {
            if(m[i]==n-1)
            {
                c++;
            }    
            
        }
        if(c>1 ||c==0)
        return -1;
        int ans=0;
         for(int i=1;i<=n;i++)
        {
            if(m[i]==n-1)
            {
               ans=i;
               break; 
            }    
            
        }
        
        for(int i=0;i<trust.size();i++)
        {
            if(trust[i][0]==ans)
            return -1;    
        }
        
        return ans;
            
    }
};