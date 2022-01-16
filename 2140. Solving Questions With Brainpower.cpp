//Editorial: https://leetcode.com/problems/solving-questions-with-brainpower/discuss/1692963/DP
class Solution {
public:
    long long mostPoints(vector<vector<int>>& q) {
        long long ans=0;
        vector<long long> dp(q.size()+1,0);
        for(int i=q.size()-1;i>=0;i--)
        {
            long long future=q[i][1]+i+1;
            if(future>=q.size())
                dp[i]=q[i][0];
            else
                dp[i]=q[i][0]+dp[future];
            ans=max(ans,dp[i]);
            dp[i]=max(dp[i],dp[i+1]);
        }
        return ans;
    }
};
