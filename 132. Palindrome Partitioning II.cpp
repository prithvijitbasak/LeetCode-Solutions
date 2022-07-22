//Approach 1: Using 2D DP. SC: O(n^2)
//Editorial: https://leetcode.com/problems/palindrome-partitioning-ii/discuss/1364206/MCM-Pattern-(In-Aditya-Verma-Format)-with-some-Optimizations-or-All-TC-Passed-or-Memorization
class Solution {
public:
    bool ispalin(string &s,int i,int j)
    {
        while(i<j)
        {
            if(s[i++]!=s[j--])
                return false;
        }
        return true;
    }
    int solve(int i,int j,string s,vector<vector<int>> &dp)
    {
        if(i>=j or ispalin(s,i,j))
            return 0;
        int ans=INT_MAX;
        if(dp[i][j]!=-1)
            return dp[i][j];
        for(int k=i;k<j;k++)
        {
            if(ispalin(s,i,k))
            {
                int temp=solve(k+1,j,s,dp)+1;
                ans=min(ans,temp);
            }
        }
        return dp[i][j]=ans;
    }
    int minCut(string s) {
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        int ans=solve(0,n-1,s,dp);
        return ans;
    }
};
//Approach 2: Using 1D DP array.
//Editorial: https://youtu.be/_H8V5hJUGd0
class Solution {
public:
    bool ispalin(string &s,int i,int j)
    {
        while(i<j)
        {
            if(s[i++]!=s[j--])
                return false;
        }
        return true;
    }
    int solve(int i,int n,string s,vector<int> &dp)
    {
        if(i==n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int ans=INT_MAX;
        for(int j=i;j<n;j++)
        {
            if(ispalin(s,i,j))
            {
                int cost=solve(j+1,n,s,dp)+1;
                ans=min(ans,cost);
            }
        }
        return dp[i]=ans;
    }
    int minCut(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
        return solve(0,n,s,dp)-1;
    }
};
