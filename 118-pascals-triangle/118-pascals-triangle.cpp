class Solution {
public:
    vector<vector<int>> generate(int numRows) {
              vector<vector<int>>generate1;
        for(int i=0;i<numRows;i++)
        {
            vector<int>v;
            for(int j=0;j<i+1;j++)
            {
                if(j==0 || j==i)
                 v.push_back(1);
                else
                {
                    int x=generate1[i-1][j]+generate1[i-1][j-1];
                v.push_back(x); 
                }
        }
            
            generate1.push_back(v);
    }
        
        return generate1;
    }
};