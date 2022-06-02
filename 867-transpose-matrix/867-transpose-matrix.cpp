class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        
        vector<vector<int>>m;
        for(int i=0;i<matrix[0].size();i++)
        {
            vector<int>v;
            for(int j=0;j<matrix.size();j++)
            v.push_back(-1);
            m.push_back(v);
        }
        
        
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            m[j][i]=matrix[i][j];
        }
        
        return m;
    }
};