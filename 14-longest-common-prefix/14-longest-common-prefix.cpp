class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string common=strs[0];
            
            for(int i=1;i<strs.size();i++)
            {
                int j=0;
                
                while(strs[i][j]==common[j] && j<common.size() && j<strs[i].size())
                j++;
                
                common=common.substr(0,j);
            }
        
          return common;
    }
};