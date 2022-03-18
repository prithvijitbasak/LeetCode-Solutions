//Editorial: https://leetcode.com/problems/maximal-square/solution/, https://youtu.be/RElcqtFYTm0
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dp(m+1,vector<int> (n+1,0));
        int mxlen=0;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(matrix[i-1][j-1]=='1')
                {
                    dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
                    mxlen=max(mxlen,dp[i][j]);
                }
            }
        }
        return mxlen*mxlen;
    }
};
