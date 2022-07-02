class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string st="";
        int s_l=s.length();
        for(int i=0;i<s_l/2;i++)
        {
            st+=s[i];
            int curr_s_l=st.length();
            if(s_l%curr_s_l!=0)
            continue;
            else
            {
                string temp="";
                int l=s_l/curr_s_l;
                for(int i=0;i<l;i++)
                temp+=st;
                
                if(temp==s)
                {
                    return true; 
                }
                   
            }
        }
        return false;
    }
};