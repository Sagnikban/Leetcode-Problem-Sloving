class Solution {
public:
    string removeDuplicates(string s) {
           stack<char> stk;
            
    for(int i=0;i<s.size();i++)
    {            
        if(stk.empty())
        {
            stk.push(s[i]);
        }
        
        else if(stk.top()!= s[i])
        {
            stk.push(s[i]);
            
        }
        else if(stk.top() == s[i])
        {
            stk.pop();
        }
        
    }
    
    string final;
    
    while(!stk.empty())
    {
        final.push_back(stk.top());
        stk.pop();
    }
    
    reverse(final.begin(),final.end());
   
    return final;
}
    
};