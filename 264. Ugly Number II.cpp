//Editorial: https://leetcode.com/problems/ugly-number-ii/discuss/69364/My-16ms-C%2B%2B-DP-solution-with-short-explanation
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n+1);
        int t2=0,t3=0,t5=0;
        dp[0]=1;
        for(int i=1;i<n;i++)
        {
            dp[i]=min(dp[t2]*2,min(3*dp[t3],5*dp[t5]));
            if(dp[i]==dp[t2]*2)
                t2+=1;
            if(dp[i]==dp[t3]*3)
                t3+=1;
            if(dp[i]==dp[t5]*5)
                t5+=1;
        }
        return dp[n-1];
    }
};
