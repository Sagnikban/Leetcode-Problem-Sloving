class Solution {
public:
    int solve(int i,vector<int>& satisfaction,int prevdishno,vector<vector<int>>&t){
        int n=satisfaction.size();
        if(i==n) 
        return 0;
        
        if(t[i][prevdishno]!=-1) return t[i][prevdishno];
        
        int select=(prevdishno+1)*satisfaction[i]+solve(i+1,satisfaction,prevdishno+1,t);
        int notselect=solve(i+1,satisfaction,prevdishno,t);
        
        return t[i][prevdishno]= max(select,notselect);
    }
    
    int maxSatisfaction(vector<int>& s) {
        sort(s.begin(),s.end());
        int n=s.size();
        vector<vector<int>>t(n+1,vector<int>(n+1,-1));
        return solve(0,s,0,t);
        
    }
};