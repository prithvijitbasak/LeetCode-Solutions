//Editorial: https://leetcode.com/problems/most-profit-assigning-work/discuss/127031/C++JavaPython-Sort-and-Two-pointer
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> jobs;
        int n=profit.size();
        int m=worker.size();
        for(int i=0;i<n;i++)
            jobs.push_back({difficulty[i],profit[i]});
        sort(jobs.begin(),jobs.end());
        sort(worker.begin(),end(worker));
        int i=0,ans=0,best=0;
        for(auto it:worker)
        {
            while(i<n and jobs[i].first<=it)
                best=max(best,jobs[i++].second);
            ans+=best;
        }
        return ans;
    }
};
