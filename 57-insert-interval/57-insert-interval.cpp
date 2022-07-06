class Solution {
public:

    vector<vector<int>> insert(vector<vector<int>>& v, vector<int>& ne) 
        
    {   
        vector<vector<int>>ans;int n=v.size();int i;
       //Push all the intervals whose starting value is less than our new interval 
       
        for(i=0;i<n;i++){
            if(v[i][0]<ne[0])
            ans.push_back(v[i]);
            else
            break;
        }
        
		//check if we can merge our new interval with the previous one
        if(!ans.empty() && ans.back()[1]>=ne[0]){
            ans.back()[1]=max(ans.back()[1],ne[1]);
        }
        else{
            ans.push_back(ne);
        }
        while(i<n)
        {
		//From now after inserting new interval there is chance of merging so keep checking
            if(!ans.empty() && ans.back()[1]>=v[i][0])
            ans.back()[1]=max(ans.back()[1],v[i][1]);
            else
            ans.push_back(v[i]);
            
            i++;
        }
        return ans;
    }
};