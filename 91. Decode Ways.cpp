//Editorial: https://leetcode.com/problems/decode-ways/discuss/1410794/C%2B%2BPython-From-Top-down-DP-to-Bottom-up-DP-O(1)-Space-Clean-and-Concise, https://youtu.be/cQX3yHS0cLo
//Approach 1: Using 1D memoization to store the previous overlaping sub-problems.
class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=s[0]=='0'?0:1;
        for(int i=2;i<=n;i++)
        {
            int onedigit=stoi(s.substr(i-1,1));
            int twodigit=stoi(s.substr(i-2,2));
            if(onedigit>=1)
                dp[i]+=dp[i-1];
            if(twodigit>=10 and twodigit<=26)
                dp[i]+=dp[i-2];
        }
        return dp[n];
    }
};
//Approach 2: Using dp with space optimisation
class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=s[0]=='0'?0:1;
        for(int i=2;i<=n;i++)
        {
            int onedigit=stoi(s.substr(i-1,1));
            int twodigit=stoi(s.substr(i-2,2));
            if(onedigit>=1)
                dp[i]+=dp[i-1];
            if(twodigit>=10 and twodigit<=26)
                dp[i]+=dp[i-2];
        }
        return dp[n];
    }
};
