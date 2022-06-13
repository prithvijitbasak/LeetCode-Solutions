//Editorial: https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/discuss/1635083/PythonC++Java-One-Pass-DP-oror-O(N)-oror-Detailed-Explanation-oror-Clean-and-Easy-to-Understand
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n=prices.size();
        vector<int> dp(n+1,0);
        long long ans=1;
        dp[0]=1;
        for(int i=1;i<n;i++)
        {
            if(prices[i]==prices[i-1]-1)
                dp[i]=dp[i-1]+1;
            else
                dp[i]=1;
            ans+=dp[i];
        }
        return ans;
    }
};
