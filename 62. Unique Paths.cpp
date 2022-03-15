//Editorial: https://leetcode.com/problems/unique-paths/discuss/22954/C%2B%2B-DP
//Approach 1: Using a matrix.
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,1));
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
        return dp[m-1][n-1];
    }
};
//Approach 2: Using a 1D array
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n,1);
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
                dp[j]+=dp[j-1];
        }
        return dp[n-1];
    }
};
