class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0,wl=0;
        int mwl=0,sw=-1;
        unordered_map<char,int>m;//map stores the last occurence index of every character
        
        while(j<s.length())
        {
            char ch =s[j];
            
            if(m.find(ch)!=m.end() and m[ch]>=i)
            {
                i=m[ch]+1;
                wl=j-i;
            }
            
            m[ch]=j;
            wl++;
            j++;
            
            if(wl>mwl)
            {
                mwl=wl;
                sw=i;
            }
        }
        
        return mwl;
    }
};