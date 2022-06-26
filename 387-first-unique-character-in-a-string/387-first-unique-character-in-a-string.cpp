class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int>a;
        for(int i=0;i<s.length();i++)
        {
            a[s[i]]++;
        }   
        
        int flag=1;
        
        
        for(int i=0;i<s.length();i++)
        {
            if(a[s[i]]==1)    
            return i;    
        }
        
        return -1;  
    }
};