//Editorial: https://leetcode.com/problems/minimum-cost-for-tickets/editorial
class Solution {
public:
    vector<int> cost;
    unordered_set<int> ust;
    vector<int> dp;
    int solve(int day)
    {
        if(day>365)
            return 0;
        if(dp[day]!=-1)
            return dp[day];
        int ans;
        if(ust.find(day)!=ust.end())
            ans=min({solve(day+1)+cost[0],solve(day+7)+cost[1],solve(day+30)+cost[2]});
        else
            ans=solve(day+1);
        return dp[day]=ans;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        cost=costs;
        dp.resize(366,-1);
        for(auto it:days)
            ust.insert(it);
        return solve(1);
    }
};
