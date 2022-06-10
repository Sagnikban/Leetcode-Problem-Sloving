
class Solution {
   public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>>q;
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> dist(m, vector<int> (n, INT_MAX));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
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
                
                if(x>=0 && x<m&& y>=0 &&  y<n)
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