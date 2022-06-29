class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>s;
        
        for(auto it:wordList)
        s.insert(it);
        
        if(s.find(endWord)==s.end())
        return 0;
        
        queue<string>q;
        q.push(beginWord);
        int depth=0;
        
        while(!q.empty())
        {
            depth++;
            int lsize=q.size();
            while(lsize--)
            {
                string curr=q.front();
                q.pop();
                
                for(int i=0;i<curr.length();i++)
                {
                    string temp=curr;
                    for(int j='a';j<='z';j++)
                    {
                        temp[i]=j;
                        
                        if(curr==temp)
                        continue;
                        
                        if(temp==endWord)
                        return depth+1;
                        
                        if(s.find(temp)!=s.end())
                        {
                         q.push(temp);
                         s.erase(temp);   
                            
                        }   
                    }
                }
            }
        }
        return 0;
        
    }
};