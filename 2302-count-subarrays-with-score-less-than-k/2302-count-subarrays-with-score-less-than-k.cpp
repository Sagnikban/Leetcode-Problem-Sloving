class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
         long long sum = 0, size = 0, ans = 0;
    queue<long long> D;
    int j = 0;
    while (j < nums.size())
    {
        sum += nums[j];
        size++;
        D.push(nums[j]);
        while (sum * size >= k && !D.empty())
            {
                sum -= D.front();
                size--;
                D.pop();
            }
            ans+=D.size();
        // cout << sum << ' ' << size << " " << ans << endl;
        j++;
    }

    return ans;
    }
};