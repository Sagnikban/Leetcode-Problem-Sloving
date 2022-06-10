class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       if(s.length()==1)
       return 1;    
        map<char,int>m;
        map<char,int>last_occur;
        int start_window=0;
        int ans=0,i;
        
        for( i=0;i<s.length();i++)
        {
           if(m.find(s[i])!=m.end())
            {
                ans=max(ans,i-start_window);
                m.clear();
               
                start_window=last_occur[s[i]]+1;
               
                for(int j=start_window;j<=i;j++)
                m[s[j]]++;
               
                cout<<start_window<<endl;
            }
            else{
                m[s[i]]++;
            }
            
            last_occur[s[i]]=i;
            
        }
       ans=max(ans,i-start_window);
        return ans;
    }
};