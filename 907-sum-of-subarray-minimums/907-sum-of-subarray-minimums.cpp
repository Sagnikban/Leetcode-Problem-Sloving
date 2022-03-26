
class Solution {
public:
    int sumSubarrayMins(vector<int>&A) {
        stack<long long>s1,s2;
        vector<long long>next_smaller(A.size());
        vector<long long>pre_smaller(A.size());
        
        for(long long i=0;i<A.size();i++)
        {
            next_smaller[i]=A.size()-1-i;
            pre_smaller[i]=i;
        }
        
        for(long long i=0;i<A.size();i++)
        {
            while(!s1.empty() && A[s1.top()]>A[i])
            {
                next_smaller[s1.top()]=i-s1.top()-1;
                s1.pop();
            }
            
            s1.push(i);
        }
        
         for(long long i=A.size()-1;i>=0;i--)
        {
            while(!s2.empty() && A[s2.top()]>=A[i])
            {
                pre_smaller[s2.top()]=s2.top()-i-1;
                s2.pop();
            }
            
            s2.push(i);
        }
        long long mod=1e9+7;
        long long ans=0;
        
        for(long long i=0;i<A.size();i++)
        {
            ans=(ans%mod +(A[i]%mod*(pre_smaller[i]+1)%mod*(next_smaller[i]+1)%mod))%mod;
           
        }
        
        return ans;
    }
};