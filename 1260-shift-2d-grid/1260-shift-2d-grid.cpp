class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& a, int k) {
        
     int m=a.size();
     int n=a[0].size();
        
        int temp=a[0][0],temp1;
        
    for(int i=1;i<=k;i++)
    {
     for(int i=0;i<m;i++)
     {
         for(int j=0;j<n;j++)
         {
            if(j!=n-1)
           {
            temp1=a[i][j+1];
             a[i][j+1]=temp;
                temp=temp1;
  
            }
             else if(i!=m-1)
             { 
                 temp1=a[i+1][0];
                 a[i+1][0]=temp;
                 temp=temp1;
             }
         }
     }
        a[0][0]=temp;
    }
        return a;
    }
};