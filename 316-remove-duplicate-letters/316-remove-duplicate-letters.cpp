class Solution {
public:
    string removeDuplicateLetters(string s) {
       
        vector<bool> exist(26,false);

        stack<char>st;
        unordered_map<char,int>m;
        
        for(int i=0;i<s.length();i++)
        m[s[i]]++; //storing the frequency of each character
        
        for(int i=0;i<s.length();i++)
        {
                 m[s[i]]--; //decrementing the count 
            
                if(exist[s[i]-'a']==false)
                {
                while(st.size()>0 && st.top()>s[i] && m[st.top()]>0)
                {
                     exist[st.top()-'a']=false;
                     st.pop();
                } 
                st.push(s[i]);
                exist[s[i]-'a']=true;
                }
        }   
        
        string ans="";
        
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
            
    }
};