//Editorial: https://leetcode.com/problems/merge-intervals/solution/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        for(auto it:intervals)
        {
            if(ans.empty() or ans.back()[1]<it[0])
                ans.push_back(it);
            else
                ans.back()[1]=max(ans.back()[1],it[1]);
        }
        return ans;
    }
};
