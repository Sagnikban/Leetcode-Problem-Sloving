class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int>pq;
        
        for(int i=0;i<nums.size();i++)
        pq.push(nums[i]);
        
        int c=0;
        while(!pq.empty())
        {
            c++;
            if(c==k)
            return pq.top();
            
            pq.pop();
        }
        return -1;
    }
};