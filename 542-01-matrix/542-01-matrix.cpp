
class Solution {
   public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>>q;
        int rows = mat.size();
         if (rows == 0)
        return mat;
        vector<vector<int>> dist(mat.size(), vector<int> (mat[0].size(), INT_MAX));
        
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]==0)
                {
                  dist[i][j] = 0;
                  q.push({i,j});  
                }
            }
        }
        
        int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
        while(!q.empty())
        {
            pair<int,int>p=q.front();
            q.pop();
            
            for(int i=0;i<4;i++)
            {
                int x=p.first+dir[i][0];
                int y=p.second+dir[i][1];
                
                if(x>=0 && x<mat.size() && y>=0 &&  y<mat[0].size())
                {
                      if (dist[x][y] > dist[p.first][p.second] + 1) {
                        dist[x][y] = dist[p.first][p.second] + 1;
                        q.push({ x, y });
                    }
                }
            }
          
        }
        
                return dist;
    }
};