class Solution {
public:
    long long int max(long long int a,long long int b)
    {
        if(a>b)
        return a;
        return b;
    }
   
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(0);
        verticalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        
        long long  int max_hori=horizontalCuts[1]-horizontalCuts[0];
        long long  int max_verti=verticalCuts[1]-verticalCuts[0];
        
        for(int i=2;i<horizontalCuts.size();i++)
       max_hori=max(horizontalCuts[i]-horizontalCuts[i-1],max_hori);   
        
             for(int i=2;i<verticalCuts.size();i++)
       max_verti=max(verticalCuts[i]-verticalCuts[i-1],max_verti);
        
        
        return (max_hori%1000000007*max_verti%1000000007)%1000000007;
        
    }
};