class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
             
     int low = nums[0];
     int high = nums[nums.size()-1];
     int index = 0;   
     for(int i = 0 ; i < nums.size() ; i++){
         if(nums[i]==target){
             index = i; 
             break;
         }
        else if(target>high){
             index = nums.size();
            break;
         }
        else if(target<low){
            index = 0 ;
            break;
         }
        else if(nums[i]>target){
             index= i ;
             break;
         }
     }
        return index;
    }
};