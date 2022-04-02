class Solution {
public:
    string s="0";
    string ans;
    int c=1;
    void helper(int n,int k)
    {
        c++;
        
    
        
        string rev;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='1')
            rev.push_back('0');
            
            if(s[i]=='0')
            rev.push_back('1');    
        }   
        reverse(rev.begin(),rev.end());
        ans=s+"1"+rev;
        s=ans;
        
        if(c==n)
        return;
        
        helper(n,k);
        
    }
    char findKthBit(int n, int k) {

        if(n==1)
        return '0';  
        
        helper(n,k);
        return ans[k-1];
    }
};