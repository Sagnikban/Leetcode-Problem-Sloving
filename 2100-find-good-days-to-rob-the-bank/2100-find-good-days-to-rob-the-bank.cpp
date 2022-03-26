class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
     int n = security.size();
    int l_dec[n];
    int s_dec[n];
    s_dec[0]=1;
	
    for(int i=1;i<n;i++)
    {
        if(security[i]<=security[i-1]) s_dec[i]=s_dec[i-1]+1;
        else s_dec[i]=1;
    }
    
    l_dec[n-1]=1;
        
    for(int i=n-2;i>=0;i--)
    {
        if(security[i]<=security[i+1]) l_dec[i]=l_dec[i+1]+1;
        else l_dec[i]=1;
    }
    
    vector<int> ans;
    
    for(int i=0;i<n;i++)
        if(s_dec[i]>time and l_dec[i]>time) ans.push_back(i);
    
    return ans;
    }
};