class Solution {
public:
    int divide(int dividend, int divisor)
    {
        
          long long ans = 0;
          double x = pow(divisor, -1);
          ans = dividend * x;
         if (ans > INT_MAX)
         return INT_MAX;
         if (ans < INT_MIN)
         return INT_MIN;
         return int(ans);

    }
};