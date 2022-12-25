//Editorial: https://youtu.be/aVIFpdAg33U
class Solution {
public:
    typedef long long ll;
    int numTilings(int n) {
        ll mod=1e9+7;
        vector<ll> dp(n+3,0);
        dp[1]=1;
        dp[2]=2;
        dp[3]=5;
        if(n<=3)
            return dp[n];
        for(ll i=4;i<=n;i++)
        {
            dp[i]=2*dp[i-1]+dp[i-3];
            dp[i]%=mod;
        }
        return dp[n];
    }
};
