//Editorial: https://leetcode.com/problems/longest-common-subsequence/discuss/351689/JavaPython-3-Two-DP-codes-of-O(mn)-and-O(min(m-n))-spaces-w-picture-and-analysis
class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int m=s1.size(),n=s2.size();
        vector<vector<int>> dp(m+1,vector<int> (n+1,0));
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0 or j==0)
                    dp[i][j]=0;
                else if(s1[i-1]==s2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};
