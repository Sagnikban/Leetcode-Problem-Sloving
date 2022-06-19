class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        queue<pair<int,int>> q;
      
         //push all 1's into queue
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)   
                    q.push({i,j});
            }
        }
        
        if(q.size()==0 || q.size()== (n*m))
         return -1;
        //queue is either empty or all filled by 1
        
        int count = -1;
        while(!q.empty())
        { 
            count++;    //increase the count
            
            int s=q.size();     
			//size contains only a particular level of elements in the queue.
			
            while(s--)
            {
                auto curr=q.front();
                int x=curr.first;
                int y=curr.second;
                q.pop();

				
				//to check in all the 4-directions
                int dx[4]={-1,0,1,0};
                int dy[4]={0,-1,0,1};

                for(int i=0;i<4;i++)
                {
                    int a=x+dx[i];
                    int b=y+dy[i];

                    if(a>=0 && a<n && b>=0 && b<m && grid[a][b]==0)
                    {
                        q.push({a,b});
						//making it visited
                        grid[a][b]= -1;
                    }
                }
            }
        }		
        return count;
    }
};