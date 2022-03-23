//Approach 1: This problem is similar to Merge Intervals problem in LeetCode. So we can just use sorting to find the solution. TC: O(nlogn) SC O(1)
//Editorial: Go to the solutions section of Merge Intervals problem.
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
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
