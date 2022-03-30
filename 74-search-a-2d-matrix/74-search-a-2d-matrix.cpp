class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int nrow=matrix.size();
        int ncolumn=matrix[0].size();
        int i=0,j=ncolumn-1;
        
      
        while((i>=0 && i<nrow) && (j>=0 && j<ncolumn))
        {
            
            if(matrix[i][j]==target)
            return true;
            
            if(matrix[i][j]>target)
            {
                j--;
            }   
            
            else if(matrix[i][j]<target)
            i++;    
            
            
          
        }
        
        return false;
    }
};