class Solution {
public:
    int minimumDeletions(string s) {
        
    int res = 0;
    int countB = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == 'b') 
        countB++;
      else {
        // option 1: remove 'a', res++
        // option 2: keep 'a', remove all preceding 'b's (res = countB)
        res = min(res + 1, countB);
      }
    }
    return res;
  }
    
};