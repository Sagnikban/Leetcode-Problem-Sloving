class Solution {
public:
    bool isPalindrome(int x) {
        
        string a=to_string(x);
        string rev=a;
        reverse(rev.begin(),rev.end());
        
        return a==rev;
    }
};