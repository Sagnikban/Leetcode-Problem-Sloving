class Solution {
public:
    bool canMeasureWater(int A, int B, int T) {
         if(A+B < T) return false;
        else if(A==T || B==T || (A+B == T)) return true;
        return T%(__gcd(A,B))==0;
    }
};