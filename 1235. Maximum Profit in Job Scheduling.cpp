//Editorial: https://leetcode.com/problems/maximum-profit-in-job-scheduling/discuss/409009/JavaC%2B%2BPython-DP-Solution,https://youtu.be/3kU7VYcmffU
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        map<int, int> dp;
        int n=startTime.size();
        vector<vector<int>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back(vector<int>{startTime[i], endTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        });
        int maxprof = 0;
        for (auto job : jobs) {
            auto it = dp.lower_bound(job[1]);
            int nowprof = (it == dp.end()) ? 0 : it->second;
            maxprof = max(maxprof, job[2] + nowprof);
            dp[job[0]] = maxprof;
        }
        return maxprof;
    }
};
