//Editorial: https://leetcode.com/problems/word-break/discuss/43814/C%2B%2B-Dynamic-Programming-simple-and-fast-solution-(4ms)-with-optimization, https://youtu.be/th4OnoGasMU
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<int> dp(n+1,0);
        set<string> dict;
        for(auto it:wordDict)
            dict.insert(it);
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j])
                {
                    string curr=s.substr(j,i-j);
                    if(dict.find(curr)!=dict.end())
                    {
                        dp[i]=1;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};
