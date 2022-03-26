class Solution {
public:
    int minCost(string colors, vector<int>& time) {
        
        int m=0,maxi=INT_MIN;
        long long sum=0,c=0;
        for(long long i=1;i<colors.length();i++)
        {
            if(colors[i]==colors[i-1])
            {
                c++;
                
                if(c==1)
                sum+=time[i]+time[i-1];
                else
                sum+=time[i];    
                
                
                maxi=max(maxi,max(time[i],time[i-1]));
            }
                
            else
            {
                c=0;
                if(maxi!=INT_MIN)
                sum-=maxi;
                
                maxi=INT_MIN;
                
            }
                
            cout<<sum<<endl;
        }
       if(maxi!=INT_MIN)
       sum-=maxi;    
        
        
        return sum;
        
      
    }
};