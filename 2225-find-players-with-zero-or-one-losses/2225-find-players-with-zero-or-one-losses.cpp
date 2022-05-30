class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>win;
        map<int,int>lose;
        map<int,int>played;
        
        
        for(int i=0;i<matches.size();i++)
        {
            win[matches[i][0]]++;
            lose[matches[i][1]]++;
            played[matches[i][0]]++;
            played[matches[i][1]]++;
        }
        vector<int>win_all;
        vector<int>lose_one;
        for(auto it:played)
        {
            if(win[it.first]==it.second&&lose[it.first]==0)
            win_all.push_back(it.first);    
            
            if(lose[it.first]==1)
            lose_one.push_back(it.first);  
        }
        
        vector<vector<int>>ans;
        ans.push_back(win_all);
        ans.push_back(lose_one);
        return ans;
    }
};