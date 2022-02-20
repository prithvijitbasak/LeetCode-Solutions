//Editorial: https://leetcode.com/problems/remove-covered-intervals/discuss/451277/JavaC%2B%2BPython-Sort-Solution
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int left=-1,right=-1,ans=0;
        sort(intervals.begin(),intervals.end());
        for(auto it:intervals)
        {
            if(it[0]>left and it[1]>right)
            {
                ans+=1;
                left=it[0];
            }
            right=max(it[1],right);
        }
        return ans;
    }
};
