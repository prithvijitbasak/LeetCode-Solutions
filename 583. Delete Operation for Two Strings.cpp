//Editorial: https://leetcode.com/problems/delete-operation-for-two-strings/solution/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size(),n=word2.size();
        vector<vector<int>> dp(m+1,vector<int> (n+1,0));
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0 or j==0)
                    dp[i][j]=0;
                else if(word1[i-1]==word2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int val=dp[m][n];
        // cout<<val<<"\n";
        return abs(val-m)+abs(val-n);
    }
};
