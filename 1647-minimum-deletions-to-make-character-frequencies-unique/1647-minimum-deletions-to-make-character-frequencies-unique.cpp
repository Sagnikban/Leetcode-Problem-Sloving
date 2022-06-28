class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int>m;
        for(int i=0;i<s.length();i++)
        m[s[i]]++;
        
        unordered_set<int>st;
        int ans=0;
        for(auto it:m)
        {
            char c=it.first;
            int f=it.second;
            if(st.find(it.second)==st.end())
            {
                st.insert(it.second);
            }
            else
            {
                
                while(st.find(f)!=st.end())
                {
                    
                    ans++;
                    f--;
                }
                 
                if(f!=0)
                st.insert(f);
            }
            
         
        }
           return ans;
    }
};