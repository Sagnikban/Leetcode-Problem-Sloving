class Solution {
public:
    bool help(vector<vector<int>>&h,int i,int j, int mid,int n,int m, int v[100][100])
    {
        if(i==n-1 && j==m-1)
        return true;
        
        v[i][j]=1;
        bool op =false;
        
        if(i>0 && v[i-1][j]==0 && abs(h[i][j]-h[i-1][j])<=mid)
        op=op||help(h,i-1,j,mid,n,m,v) ;  
        
        if(j>0 && v[i][j-1]==0 && abs(h[i][j]-h[i][j-1])<=mid)
        op=op||help(h,i,j-1,mid,n,m,v)  ;  
        
          if(i<n-1 && v[i+1][j]==0 && abs(h[i][j]-h[i+1][j])<=mid)
        op=op||help(h,i+1,j,mid,n,m,v)  ;  
        
          if(j<m-1 && v[i][j+1]==0 && abs(h[i][j]-h[i][j+1])<=mid)
        op=op||help(h,i,j+1,mid,n,m,v)  ;  
        
        
        return op;
        
            
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int s=0;
        int e=INT_MAX;
        int ans=INT_MAX;
        int n=heights.size();
        int m=heights[0].size();
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            int v[100][100];
            memset(v,0,sizeof v);
            if(help(heights,0,0,mid,n,m,v))
            {
                ans=min(mid,ans);
                e=mid-1;
            }    
                else
                {
                    s=mid+1;
                }
            
        }
        
        return ans;
    }
};