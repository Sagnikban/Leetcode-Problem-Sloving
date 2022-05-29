class Solution {
public:
    string removeOuterParentheses(string str) {
           string ans = "";
        stack<char> s;
        
        for(char c : str){
            if(c == '(') s.push(c);
            if(s.size() > 1) ans += c;
            if(c == ')') s.pop();
        }
        
        return ans;
    }
};