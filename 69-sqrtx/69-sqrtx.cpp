class Solution {
public:
    int binarysearch(int x)
    {
        int s=0;
        int e=x;
      
        int ans=0;
        while(s<=e)
        {
            long long   mid = s+(e-s)/2;
            long long sq=mid*mid;
            if(sq==x)
            return mid;
            else if(sq>x)
            e=mid-1; 
            else if(sq<x){
            s=mid+1;
            ans=mid;
                }
         
        }
        return ans;
    }
    int mySqrt(int x) {
       return binarysearch(x); 
    }
};