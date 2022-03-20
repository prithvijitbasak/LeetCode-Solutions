//Editorial: https://leetcode.com/problems/coin-change/discuss/1371738/C%2B%2B-Recursion-greater-DP-Memoization-greater-DP-Tabulation
//Approach 1: Using 2D DP technique.
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int> (amount+1,0));
        for(int i=0;i<=amount;i++)
            dp[0][i]=INT_MAX-1;
        for(int i=1;i<=n;i++)
            dp[i][0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=amount;j++)
            {
                if(coins[i-1]<=j)
                    dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][amount]==INT_MAX-1?-1:dp[n][amount];
    }
};
