class Solution {
public:
    static bool sortbys(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second>  b.second);
}
  
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        vector<pair<int,int>>v;
        for(int i=0;i<boxTypes.size();i++)
        v.push_back({boxTypes[i][0],boxTypes[i][1]});
        sort(v.begin(),v.end(),sortbys);
        int c=0,ans=0;
        for(int i=0;i<v.size();i++)
        {
            
            if(truckSize==0)
            break;
            
            int x=min(truckSize,v[i].first);
            truckSize-=x;
            
            ans+=v[i].second*x;
           
        }
        return ans;
    }
};