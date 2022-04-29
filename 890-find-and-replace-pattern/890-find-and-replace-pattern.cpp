class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        for(int i=0;i<words.size();i++)
        {
            
            unordered_map<char,char>m;
            unordered_map<char,char>m1;
            int flag=1;
            for(int j=0;j<words[i].size();j++)
            {
                if(m.find(pattern[j])==m.end())
                {
                m.insert({pattern[j],words[i][j]});
                    
                if(m1.find(words[i][j])!=m.end()&& m1[words[i][j]]!=pattern[j])
                {
                    flag=2;
                    break;
                }
                    else
                m1.insert({words[i][j],pattern[j]});
                  }
                else 
                {
                    if(m[pattern[j]]!=words[i][j] || m1[words[i][j]]!=pattern[j])
                    {
                        flag=2;
                        break;
                    }    
                }
        
                }
            
            if(flag==1)
            {
               ans.push_back(words[i]); 
            }
        }
        
        return ans;
        }
    
};