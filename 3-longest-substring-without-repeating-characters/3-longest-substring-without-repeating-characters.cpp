class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       map<char,int>m;
        int i=0,j=0;
        int window_length=0,max_window_length=0;
        while(j<s.length())
        {
 
            if(m.find(s[j])!=m.end() && m[s[j]]>=i)
            i=m[s[j]]+1;   
                
            
            m[s[j]]=j;
           
            window_length=j-i+1;
            
            if(window_length>max_window_length)
            max_window_length=window_length;    
            
            j++;
            
            cout<<window_length<<endl;
            
        }
        return max_window_length;
    }
};