class Solution {
public:
    int bs(vector<vector<int>>& intervals, int target) {
        int l = 0, r = intervals.size()-1;
        int idx = 0;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (intervals[m][0] == target) return m;
            else if (intervals[m][0] < target) l = m + 1;
            else r = m - 1;
        }
        return l;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int idx = bs(intervals, newInterval[0]);
        intervals.insert(intervals.begin()+idx, newInterval);
        vector<vector<int> > ans;
        ans.push_back(intervals[0]);
        
        for(int i=1; i<intervals.size(); i++)
        {
            int ax = ans[ans.size()-1][0];
            int ay = ans[ans.size()-1][1];
            int bx = intervals[i][0];
            int by = intervals[i][1];
            if(bx <= ay) {
                ans[ans.size()-1][1] = max(ay, by);
            } else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};