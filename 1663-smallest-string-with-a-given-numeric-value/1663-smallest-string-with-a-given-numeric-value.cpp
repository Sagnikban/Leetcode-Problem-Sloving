class Solution {
public:
    string getSmallestString(int n, int k) {
        
         string ans="";
        int a = (26*n-k)/25; //calculate 'a's required
        ans.insert(0, a, 'a');
        int z = (k-a)/26;//calculating 'z's required
        int inter = k-a-z*26;//finding intermediate letter between a's and z's
        if(inter>1)
            ans+=('a'+inter-1);
        ans.insert(ans.size(), z, 'z');
        return ans;
    }
};