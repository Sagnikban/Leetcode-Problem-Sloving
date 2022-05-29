class Solution {
public:
    string removeOuterParentheses(string str) {
           string ans = "";
        stack<char> s;
        
        for(int i=0;i<str.size();i++)
        {
            if(str[i] == '(')
            s.push(str[i]);
            if(s.size() > 1) 
            ans += str[i];
            if(str[i]== ')')
            s.pop();
        }
        
        return ans;
    }
};