class Solution {
public:

    bool hasAllCodes(string s, int k) {
        
        set<string>se;
        
        if(k>s.length())
        return false;   
        
        for(int i=0;i<s.length()-k+1;i++)
        se.insert(s.substr(i,k)); 
        
          
        if(se.size()==pow(2,k))
        return true;
        
        return false;
    }
};