class Solution {
public:
    string reverseStr(string s, int k) {
        
   int r=min(k,(int)s.length());
   for(int i=0; i<s.size(); )
    {
      reverse(s.begin()+i,s.begin()+r);
      i=i+2*k;
      r= min(i+k,(int)s.length());
     }
       return s;
    }
    
};