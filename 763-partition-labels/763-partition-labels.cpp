class Solution {
public:
    vector<int> partitionLabels(string s) {
         int prv=-1,max=0;
        unordered_map<char,int> um;
        vector<int> v;
        for(int i=0;i<s.size();i++)
        um[s[i]]=i;
        
        for(int i=0;i<s.size();i++)
        {
            if(um[s[i]]>max)
            max=um[s[i]];
            
            if(i==max)
            {
                v.push_back((max-prv));
                prv=max;
            }
            
        }
        return v;
    }
};