class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        
        int ans=0;
        for(int i=0;i<nums1.size();i++)
        {
            int l=i;
            int h=nums2.size()-1;
            
            while(l<=h)
            {
            
                int mid=l+(h-l)/2;
                
                if(nums2[mid]>=nums1[i])
                {
                    ans=max(ans,mid-i);
                    l=mid+1;
                    
                }
                else
                {
                    h=mid-1;
                }
            }
            
        }
        return ans;
    }
};