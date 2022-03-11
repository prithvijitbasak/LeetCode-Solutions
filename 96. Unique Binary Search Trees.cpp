//Editorial: https://leetcode.com/problems/unique-binary-search-trees/discuss/1565543/C%2B%2BPython-5-Easy-Solutions-w-Explanation-or-Optimization-from-Brute-Force-to-DP-to-Catalan-O(N)
//Approach 1: Using dp 
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
                dp[i]+=dp[j-1]*dp[i-j];
        }
        return dp[n];
    }
};
//Approach 2: Using space optimised mathematical technique(Catalan Number formula).
class Solution {
public:
    typedef long long ll;
    ll nCr(int n,int r)
    {
        ll ans=1;
        for(int i=0;i<r;i++)
        {
            ans*=(n-i);
            ans/=(i+1);
        }
        return ans;
    }
    int numTrees(int n) {
        return nCr(2*n,n)/(n+1);
    }
};
