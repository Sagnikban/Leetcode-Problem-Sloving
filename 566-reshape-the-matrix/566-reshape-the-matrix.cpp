class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        int m = mat.size(); 
        int n = mat[0].size();
        
        vector<vector<int>> res;
        vector<int> res1;
        
        if(m*n != r*c )
        {
            return mat;
        }
        
        int col= 0;
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++)
            {
                res1.push_back(mat[i][j]);
                col++;
            
                if(col == c){
                    col = 0;
                    res.push_back(res1);
                    res1.clear();
                }
            }
        }
        return res;
        
    }
};