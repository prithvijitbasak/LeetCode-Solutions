//Editorial: https://leetcode.com/problems/out-of-boundary-paths/discuss/632968/Hurrah!-My-first-DP-Accepted-Solution-C++
class Solution {
public:
    int mod=1e9+7;
    int solve(int m,int n,int maxmoves,int x,int y,vector<vector<vector<int>>> &dp,int moves)
    {
        if(x>=m or y>=n or y<0 or x<0)
            return 1;
        if(moves==maxmoves)
            return 0;
        if(dp[moves][x][y]!=-1)
            return dp[moves][x][y]%mod;
        int temp=0;
        temp=(temp+solve(m,n,maxmoves,x+1,y,dp,moves+1))%mod;
        temp=(temp+solve(m,n,maxmoves,x,y+1,dp,moves+1))%mod;
        temp=(temp+solve(m,n,maxmoves,x-1,y,dp,moves+1))%mod;
        temp=(temp+solve(m,n,maxmoves,x,y-1,dp,moves+1))%mod;
        dp[moves][x][y]=temp%mod;
        return dp[moves][x][y];
    }
    int findPaths(int m, int n, int maxmoves, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(maxmoves+1,vector<vector<int>> (m+1,vector<int> (n+1,-1)));
        dp[maxmoves][m][n]=solve(m,n,maxmoves,startRow,startColumn,dp,0);
        return dp[maxmoves][m][n];
    }
};
