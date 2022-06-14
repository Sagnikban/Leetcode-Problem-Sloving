class Solution {
public:
    int peak_find(vector<int>& arr, int low, int high)
    {
        if(low<=high)
        {
            int mid = low+(high-low)/2;
            if(arr[mid] > arr[mid-1]  &&  arr[mid] > arr[mid+1])
                return mid;
            
            else if(arr[mid] > arr[mid-1]  &&  arr[mid] < arr[mid+1])
                return peak_find(arr, mid+1, high);
            
            else 
                return peak_find(arr, low, mid);
        }
        return 10;
    }
    
    int peakIndexInMountainArray(vector<int>& A) {
        int sz = A.size();
        int k = peak_find(A, 0, sz-1);
        return k;
    }
};