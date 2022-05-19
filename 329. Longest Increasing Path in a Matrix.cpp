//Editorial: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/discuss/1151423/C++-Optimization-from-Brute-Force-to-DP-or-Easy-Solution-w-Explanation
//Approach 1: Using memoization. TC: O(m*n) SC: O(m*n).
class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
    int m,n,ans;
    int solve(vector<vector<int>> &matrix,int i,int j)
    {
        if(dp[i][j])
            return dp[i][j];
        dp[i][j]=1;
        for(int k=0;k<4;k++)
        {
            int dx=i+dir[k][0];
            int dy=j+dir[k][1];
            if(dx<0 or dx>=m or dy<0 or dy>=n or matrix[dx][dy]<=matrix[i][j])
                continue;
            dp[i][j]=max(dp[i][j],1+solve(matrix,dx,dy));
        }
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m=matrix.size();
        n=matrix[0].size();
        dp.resize(m,vector<int>(n));
        ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                ans=max(ans,solve(matrix,i,j));
        }
        return ans;
    }
}; 
