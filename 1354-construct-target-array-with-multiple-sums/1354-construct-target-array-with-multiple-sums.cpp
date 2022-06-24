class Solution {
public:
    bool isPossible(vector<int>& target) {
        
       priority_queue<long long> pq;
        long long sum = 0;
        for (long long x : target){
            sum += x;
            pq.push(x);
        }
        while (pq.top() != 1) 
        {
            long long x = pq.top();
            pq.pop();
            sum-=x;
            if (x<= sum || sum < 1) 
            return false;
            x%= sum;
            sum+=x;
            pq.push(x?x: sum);
        }
        return true;
    }
};