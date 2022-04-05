class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int i=0;
        int j=height.size()-1;
        int ans=INT_MIN;
        int area;
        while(i<j)
        {
            area=(j-i)* min(height[i],height[j]);
            ans=max(ans,area);
            
            if(height[i]<height[j])
            {
                i++;
                
            }
            else
            {j--;}
        }
        
        return ans;
    }
};