//Editorial: https://leetcode.com/problems/distinct-subsequences/discuss/37327/Easy-to-understand-DP-in-Java/35362
class Solution {
public:
    typedef long long ll;
    int numDistinct(string s, string t) {
        ll m=s.size(),n=t.size();
        vector<vector<ll>> dp(m+1,vector<ll> (n+1,0));
        for(ll i=0;i<=m;i++)
            dp[i][0]=1;
        for(ll i=1;i<=m;i++)
        {
            for(ll j=1;j<=n;j++)
            {
                if(s[i-1]==t[j-1])
                    dp[i][j]=(int)(dp[i-1][j-1]+dp[i-1][j]);
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[m][n];
    }
};
