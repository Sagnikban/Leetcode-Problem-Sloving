class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
       
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<arr.size();i++)
        {
            if(binary_search(arr.begin(),arr.end(),2*arr[i]))
            {
                
               auto it=lower_bound(arr.begin(),arr.end(),2*arr[i]);
               int j=it-arr.begin();
               if(j!=i)
               return true;
            }
                     
        }
        return false;
    }
};