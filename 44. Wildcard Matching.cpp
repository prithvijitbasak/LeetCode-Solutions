//Editorial: https://youtu.be/3ZDZ-N0EPV0, https://leetcode.com/problems/wildcard-matching/discuss/1001130/C%2B%2B-Clean-and-concise-bottom-up-dp-code-with-detailed-explanation-easy-to-understand.
class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
        vector<vector<int>> dp(m+1,vector<int> (n+1,0));
        dp[0][0]=1;
        for(int j=0;j<n and p[j]=='*';j++)
        {
            dp[0][j+1]=1;
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(p[j-1]=='*')
                    dp[i][j]=dp[i-1][j] or dp[i][j-1];
                else
                    dp[i][j]=(s[i-1]==p[j-1] or p[j-1]=='?') and dp[i-1][j-1];
            }
        }
        return dp[m][n];
    }
};
