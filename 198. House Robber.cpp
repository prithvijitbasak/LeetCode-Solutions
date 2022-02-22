//Editorial: https://leetcode.com/problems/house-robber/discuss/156523/From-good-to-great.-How-to-approach-most-of-DP-problems.
//Approach 1: Using bottom-up approach
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1);
        dp[0]=0,dp[1]=nums[0];
        for(int i=1;i<n;i++)
        {
            int val=nums[i];
            dp[i+1]=max(dp[i],dp[i-1]+val);
        }
        return dp[n];
    }
};
//Approach 2: Space optimised
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev1=0,prev2=0;
        for(int i=0;i<n;i++)
        {
            int temp=prev1;
            prev1=max(prev2+nums[i],prev1);
            prev2=temp;
        }
        return prev1;
    }
};
