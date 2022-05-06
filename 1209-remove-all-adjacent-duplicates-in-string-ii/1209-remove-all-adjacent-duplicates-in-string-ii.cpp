class Solution {
public:
    string removeDuplicates(string s, int k) {
       stack<pair<char,int>>st;
        
    for(int i=0;i<s.length();i++)
    {
        if(st.empty()||st.top().first!=s[i])
        st.push({s[i],1});
        else
        {
        st.top().second++;
        if(st.top().second==k)
        {
            st.pop();    
        }
        }
    }
        
        string ans="";
        while(!st.empty())
        {
            while(st.top().second--)
            ans+=st.top().first;
            
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
 
    
    
    return ans;
    }
};