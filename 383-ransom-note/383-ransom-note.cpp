class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        map<char,int>m;
        for(auto it:magazine)
        m[it]++;
        
        for(auto it:ransomNote)
        {
            if(m.find(it)==m.end() || m[it]==0)
            return false;    
            else
            m[it]--;    
        }
        
          
        
        return true;
    }
};