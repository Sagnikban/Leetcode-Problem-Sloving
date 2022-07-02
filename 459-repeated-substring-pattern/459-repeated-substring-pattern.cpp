class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string st="";
        for(int i=0;i<s.length()/2;i++)
        {
            st+=s[i];
            if(s.length()%st.length()!=0)
            continue;
            
            else
            {
                string temp="";
                int l=s.length()/st.length();
                for(int i=0;i<l;i++)
                temp+=st;
                
                if(temp==s)
                {
                    cout<<st<<endl;
                    return true; 
                }
                   
            }
        }
        return false;
    }
};