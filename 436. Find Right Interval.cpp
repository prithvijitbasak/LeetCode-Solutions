//Editorial: https://leetcode.com/problems/find-right-interval/discuss/814263/c++-Using-Map-And-Bainary-Search
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int,int> mp;
        int n=intervals.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++)
            mp[intervals[i][0]]=i;
        for(int i=0;i<n;i++)
            ans[i]=mp.lower_bound(intervals[i][1])!=mp.end()?mp.lower_bound(intervals[i][1])->second:-1;
        return ans;
    }
};
