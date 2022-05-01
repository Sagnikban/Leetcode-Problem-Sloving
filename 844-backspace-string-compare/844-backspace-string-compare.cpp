class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        string a="",b="";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='#'&& a.size()>=1)
            a.pop_back();
            else if(s[i]!='#')
            a+=s[i];    
        }
        
        for(int i=0;i<t.length();i++)
        {
            if(t[i]=='#'&& b.size()>=1)
            b.pop_back();
            else if(t[i]!='#')
            b+=t[i];    
        }
        cout<<a<<" "<<b<<endl;
        return a==b;
    }
};