class Solution {
public:
    int numTeams(vector<int>& rating) {
        
        int ans=0;
        for(int i=0;i<rating.size();i++)
        {
            int c=0,d=0,e=0,f=0;
            for(int j=0;j<i;j++)
            {
                if(rating[j]<rating[i])
                c++;
                
                 if(rating[j]>rating[i])
                d++;    
                
            }
              for(int j=i+1;j<rating.size();j++)
            {
                if(rating[j]<rating[i])
                e++;   
                if(rating[j]>rating[i])
                f++;    
                
            }
            //cout<<c<<" "<<d<<" "<<e<<" "<<f<<"ans="<<ans<< endl;
            ans+=c*f+d*e;
        }
        
        return ans;
    }
};