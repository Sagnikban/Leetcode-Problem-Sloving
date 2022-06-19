class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
         queue<int> q;
        vector<int> answer(n, -1);
        vector<vector<int>> adjR(n), adjB(n);
        
        for(vector<int> v : redEdges)
            adjR[v[0]].push_back(v[1]);
        
        for(vector<int> v : blueEdges)
            adjB[v[0]].push_back(v[1]);
        
        vector<vector<bool>> vis(2, vector<bool>(n, false));
        
        //starting from redEdges
        q.push(0);
        vis[0][0]=1;
        int dis = 0;
        
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0; i<sz; i++)
            {
                int front = q.front();
                q.pop();
                if(answer[front] == -1) answer[front] = dis;

                if(dis%2==0)
                {
                    for(int nbr : adjR[front])
                    {
                        if(!vis[1][nbr])
                            q.push(nbr);
                        vis[1][nbr]=1;
                    }
                }
                else
                {
                    for(int nbr : adjB[front])
                    {
                        if(!vis[0][nbr])
                            q.push(nbr);
                        vis[0][nbr]=1;
                    }
                }
            }
            dis++;
        }
        
        for(int i=0; i<n; i++) vis[0][i]=0, vis[1][i]=0;
        
        //start from blueEdges
        q.push(0);
        vis[1][0]=1;
        dis=0;
        
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0; i<sz; i++)
            {
                int front = q.front();
                q.pop();
                
                if(answer[front] == -1) 
                    answer[front] = dis;
                else 
                    answer[front] = min(answer[front], dis);

                if(dis%2)
                {
                    for(int nbr : adjR[front])
                    {
                        if(!vis[0][nbr])
                            q.push(nbr);
                        vis[0][nbr]=1;
                    }
                }
                else
                {
                    for(int nbr : adjB[front])
                    {
                        if(!vis[1][nbr])
                            q.push(nbr);
                        vis[1][nbr]=1;
                    }
                }
            }
            dis++;
        }
        return answer;  
    }
};