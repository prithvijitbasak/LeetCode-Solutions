//Editorial: https://leetcode.com/problems/minimum-cost-to-split-an-array/solutions/3083916/c-based-on-today-s-daily-challenge-simpler-code/?orderBy=most_votes
class Solution {
public:
    int solve(int idx,vector<int> &dp,vector<vector<int>> &tlen,vector<int> &nums,int &k)
    {
        if(idx>=nums.size())
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        int minans=INT_MAX;
        for(int i=idx;i<nums.size();i++)
        {
            int val=k+tlen[idx][i];
            int fnd=solve(i+1,dp,tlen,nums,k);
            minans=min(minans,val+fnd);
        }
        return dp[idx]=minans;
    }
    int minCost(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>> tlen(n,vector<int> (n,0));
        for(int i=0;i<n;i++)
        {
            vector<int> mp(1001,0);
            int cnt=0;
            for(int j=i;j<n;j++)
            {
                if(mp[nums[j]]!=0)
                {
                    if(mp[nums[j]]==1)
                        cnt+=2;
                    else
                        cnt+=1;
                }
                mp[nums[j]]+=1;
                tlen[i][j]=cnt;
            }
        }
        vector<int> dp(n,-1);
        int ans=solve(0,dp,tlen,nums,k);
        return ans;
    }
};
