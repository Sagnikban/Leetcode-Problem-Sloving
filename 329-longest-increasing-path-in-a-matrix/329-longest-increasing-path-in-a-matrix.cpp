class Solution {
    int maxi(int a,int b,int c,int d)
    {
        return max(a,max(b,max(c,d)));
    }
    int dp(vector<vector<int> > & matrix,vector<vector<int> > &memo, int i, int j)
    {
        int m=matrix.size(),n=matrix[0].size();
        if(i<0 or j<0 or i>=m or j>=n)
        {
            return 0;
        }
        if(memo[i][j]!=-1)
        {
            return memo[i][j];
        }
        
        int top=0,down=0,left=0,right=0;
        
        if(i-1>=0 and matrix[i-1][j]>matrix[i][j])
        {
            top=dp(matrix,memo,i-1,j);
        }
        
        if(i+1<m and matrix[i+1][j]>matrix[i][j])
        {
            down=dp(matrix,memo,i+1,j);
        }
        
        if(j-1>=0 and matrix[i][j-1]>matrix[i][j])
        {
            left=dp(matrix,memo,i,j-1);
        }
        
        if(j+1<n and matrix[i][j+1]>matrix[i][j])
        {
            right=dp(matrix,memo,i,j+1);
        }
        
        
        memo[i][j]=1+maxi(top,down,left,right);
        
        return memo[i][j];
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size(),ans=INT_MIN;
        vector<vector<int> > memo(m,vector<int>(n,-1));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans=max(ans,dp(matrix,memo,i,j));
            }
        }
        
        return ans;
    }
};