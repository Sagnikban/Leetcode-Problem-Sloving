class Solution {
public:
      bool checkReach(vector<int>& arr,vector<int>& vis,int i)
    {
        if(vis[i])
        return false;
          
        vis[i]=1;
          
        if(arr[i]==0)
        return true;
        
        if(i-arr[i]>=0)
        if(checkReach(arr,vis,i-arr[i]))
         return true;
                
        if(i+arr[i]<arr.size())
        if(checkReach(arr,vis,i+arr[i]))
        return true;
          
        return false;
    }
    
    bool canReach(vector<int>& arr, int start) {
        vector<int>vis(arr.size(),0);
        return checkReach(arr,vis,start);
            
    }
};