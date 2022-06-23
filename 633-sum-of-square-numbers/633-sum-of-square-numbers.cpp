#define ll long long
class Solution {
public:
    bool binary_search(ll s, ll e, int n) {
        if (s > e)
            return false;
        ll mid = s + (e - s) / 2;
        if (mid * mid == n)
            return true;
        if (mid * mid > n)
        return binary_search(s, mid - 1, n);
        return binary_search(mid + 1, e, n);
    }
    bool judgeSquareSum(int c) {
        
       for (ll a = 0; a * a <= c; a++) {
            int b = c - (int)(a * a);
            if (binary_search(0, b, b))
                return true;
        }
        return false;
    }
};