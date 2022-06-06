class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int ans = 0, n2 = nums2.size(), j = -1;
        
        for(int i=0;i<n;i++) {
            while(j+1<n2 and nums2[j+1]>=nums1[i]) {
                j++;
            }
            ans = max(ans,j-i);
        }
        return ans;
    }
};