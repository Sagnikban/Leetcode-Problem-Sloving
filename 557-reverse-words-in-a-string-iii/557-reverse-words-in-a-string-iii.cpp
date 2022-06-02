class Solution {
public:
    string reverseWords(string s) {
        
        string rev="";
        string ans="";
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ')
            {
                reverse(rev.begin(),rev.end());
                ans+=rev;
                ans+=' ';
                rev="";
            }
            else
            rev+=s[i]; 
            
        }
        
        reverse(rev.begin(),rev.end());
        ans+=rev;
        
        return ans;
        
    }
};