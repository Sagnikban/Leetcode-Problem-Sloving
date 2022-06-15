class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int yes = 0;
        sort(arr2.begin(),arr2.end());
        
        for(int i=0;i<arr1.size();i++){
            int s = 0;
            int e = arr2.size()-1;
            int mid;
            while(s<=e){
                mid = s + (e-s)/2;
                int ans = arr2[mid]-arr1[i];
                if(-d<=ans && ans<=d) {
                    break;
                }else if(ans<d){
                    s = mid+1;
                }else e = mid-1;
            }
            if(s>e) yes++;
        }
        return yes;
        
    }
};