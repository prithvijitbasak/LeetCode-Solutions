//Editorial: https://youtu.be/Ur55Yb7-dzc , https://leetcode.com/problems/best-team-with-no-conflicts/solutions/899475/fairly-easy-dp/?orderBy=most_votes 
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> nums;
        int n=scores.size();
        for(int i=0;i<n;i++)
            nums.push_back({ages[i],scores[i]});
        sort(nums.rbegin(),nums.rend());
        int ans=0;
        vector<int> dp(n,0);
        for(int i=0;i<n;i++)
        {
            dp[i]=nums[i].second;
            for(int j=0;j<i;j++)
            {
                if(nums[j].second>=nums[i].second)
                    dp[i]=max(dp[i],dp[j]+nums[i].second);
            }
            ans=max(dp[i],ans);
        }
        return ans;
    }
};
