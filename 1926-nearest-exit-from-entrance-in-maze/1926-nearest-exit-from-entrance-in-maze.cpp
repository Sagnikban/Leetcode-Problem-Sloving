class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
         queue<pair<int,int>> q;
        q.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]]='#';
        int steps=1;
        
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        while(!q.empty())
        {
            int l=q.size();
            for(int i=0;i<l;i++)
            {
                auto p=q.front();
                q.pop();
                
                for(int i=0;i<4;i++)
                {
                    int x=p.first+dx[i];
                    int y=p.second+dy[i];
                    
                    if(x>=0 && x<maze.size() && y>=0 && y<maze[0].size() && maze[x][y]=='.')
                    {
                        if(x==0 || y==0 || x==maze.size()-1 || y==maze[0].size()-1)
                            return steps;
                        
                        q.push({x,y});
                        maze[x][y]='#';
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};