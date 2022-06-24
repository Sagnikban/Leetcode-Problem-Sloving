class Solution {
using vc = vector<char>;
using vi = vector<int>;
 
public:
    int maxN=310;
    int rec(int row, int col, vector<vc>&matrix, vector<vi>&dp){
        if(row==0 || col==0){
            if(matrix[row][col]=='1') return dp[row][col]= 1;
            else return dp[row][col]=0;
         }
 
        if(dp[row][col]!= -1) return dp[row][col];
 
        int ans =0;
        int top=rec(row-1, col,matrix, dp);
        int left=rec(row,col-1,matrix,dp);
        int diag= rec(row-1,col-1, matrix,dp); 
        
        if(matrix[row][col]=='1' && row-1>=0 && col-1>=0)
        ans =min(left,min(top,diag))+1;
        
        else if(row-1>=0 && col-1>=0 && matrix[row][col]== '0')
        ans=0;
         
     
        
        return dp[row][col]= ans;
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
         int row = matrix.size();
         int col = matrix[0].size();
         vector<vector<int>>dp(310, vector<int>(310, -1));
      
         int ans = rec(row-1, col-1, matrix,dp);
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(i==0 || j==0)
                {
                    if(matrix[i][j]=='0')
                    dp[i][j]=0;
                    else
                    dp[i][j]=1;    
                }    
            }   
        }
        
        int maxi=0;
          for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
                
            {
                cout<<dp[i][j]<<" ";
                maxi=max(maxi,dp[i][j]);
            }
                cout<<endl;
            
            
        }
        return maxi*maxi;
    }
};