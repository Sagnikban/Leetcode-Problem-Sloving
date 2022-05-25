class Solution {
public:
    int longestValidParentheses(string s) {
                
         int left=0,right=0,maxi=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
            left++;
            else
            right++;
            
            if(left==right)
            {
                maxi=max(left+right,maxi);
            }
            else if(right>=left)
            {
                right=0;
                left=0;
            }
        } 
        
        left=0;
        right=0;
        
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s[i]=='(')
            left++;
            else
            right++;
            
            if(left==right)
            {
                maxi=max(left+right,maxi);
            }
            else if(left>=right)
            {
                right=0;
                left=0;
            }
        } 
        
      return maxi;
        
        

    }
};