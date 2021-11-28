//Mathematical approach: 
//Editorial: https://leetcode.com/problems/divisor-game/discuss/274566/just-return-N-2-0-(proof)
class Solution {
public:
    bool divisorGame(int n) {
        if(n&1)
            return false;
        else
            return true;
    }
};
//Dynamic Programmic approach: 
//Editorial: https://leetcode.com/problems/divisor-game/discuss/323884/c%2B%2B-dp-100-time-complexity
class Solution {
public:
    bool divisorGame(int n) {
        vector<bool> dp(n+1,false);
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j*j<=i;j++)
            {
                if(i%j==0 and !dp[i-j])
                    dp[i]=true;
            }
        }
        return dp[n];
    }
};
