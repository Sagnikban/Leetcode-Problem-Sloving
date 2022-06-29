class Solution {
public:
   void dfs(vector<vector<int>>& stones,int n,bool*visited,int s,int &result){
        visited[s]=true;
        for(int i=0;i<n;i++){
            if(!visited[i] ){
                if(stones[i][0]==stones[s][0] || stones[i][1]==stones[s][1]){
                    result++;
                    dfs(stones,n,visited,i,result);
                }
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        bool *visited=new bool[n];
        
        for(int i=0;i<n;i++){
            visited[i]=false;
        }
        
        int result=0;
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(stones,n,visited,i,result);
            }
        }
        return result;
        
    }
};