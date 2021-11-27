//Editorial: https://youtu.be/UmMh7xp07kY
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        if(sum%2)
            return false;
        return subsetsum(nums,sum/2);
    }
    bool subsetsum(vector<int> &nums,int sum)
    {
        int n=nums.size();
        vector<vector<bool>> dp(n+1,vector<bool> (sum+1));
        for(int i=0;i<=n;i++)
            dp[i][0]=true;
        for(int i=1;i<=sum;i++)
            dp[0][i]=false;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(nums[i-1]<=j)
                    dp[i][j]=dp[i-1][j] or dp[i-1][j-nums[i-1]];
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
};
