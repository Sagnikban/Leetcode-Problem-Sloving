class Solution {
public:
    int getNext(int n) {
        int totalSum = 0;
        while (n > 0) {
            int d = n % 10;
            n = n / 10;
            totalSum += d * d;
        }
        return totalSum;
    }

    bool isHappy(int n) {
       set<int>s;
        while(n!=1 && s.find(n)==s.end())
        {
            s.insert(n);
            n = getNext(n);
        }
       return  n==1;
        
    }
};