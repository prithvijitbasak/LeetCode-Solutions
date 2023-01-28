//Editorial: https://leetcode.com/problems/word-break/solutions/127450/word-break/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> ust(wordDict.begin(),wordDict.end());
        int n=s.size();
        vector<int> dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(dp[j] and ust.find(s.substr(j,i-j))!=ust.end())
                {
                    dp[i]=1;
                    break;
                }
            }
        }
        return dp[n];
    }
};
