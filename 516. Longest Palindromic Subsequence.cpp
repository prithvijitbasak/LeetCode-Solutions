//Editorial: https://leetcode.com/problems/longest-palindromic-subsequence/discuss/1468396/C%2B%2BPython-2-solutions%3A-Top-down-DP-Bottom-up-DP-O(N)-Space-Clean-and-Concise, https://youtu.be/wuOOOATz_IA
class Solution {
public:
    int longestPalindromeSubseq(string s1) {
        string s2=s1;
        reverse(s2.begin(),s2.end());
        int n=s1.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0 or j==0)
                    dp[i][j]=0;
                else if(s1[i-1]==s2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][n];
    }
};
