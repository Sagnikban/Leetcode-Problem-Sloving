class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>same_letter;
        
            int ans=0;
        
        for(int i=0;i<words.size();i++)
        {
            if(words[i][0]==words[i][1])
            {
            same_letter[words[i]]++;    
            }
        } 
        
        for(auto it:same_letter)
        {
            int x=it.second/2;
            
            ans+=x*4;    
            
            it.second-=x*2;
        }
        
        for(auto it:same_letter)
        {
            if(it.second%2==1)
            {
                ans+=2;
                break;
            }    
                
        }
       
        unordered_map<string,int>p;
    
        for(int i=0;i<words.size();i++)
        {
            if(words[i][0]==words[i][1])
            continue;
            
            reverse(words[i].begin(),words[i].end());
            if(p.find(words[i])!=p.end() && p[words[i]]!=0)
            {
                auto it=p.find(words[i]);
                p[words[i]]-=1;
                ans+=4;
            }    
             else
             {
                 
             reverse(words[i].begin(),words[i].end());
             p[words[i]]++;
             }

            
        }
        return ans;
    }
};