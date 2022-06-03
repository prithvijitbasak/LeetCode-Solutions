//Editorial: https://leetcode.com/problems/interleaving-string/solution/
//Approach 1: Using 2D DP
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int a=s1.size(),b=s2.size(),c=s3.size();
        if((a+b)!=c)
            return false;
        vector<vector<int>> dp(a+1,vector<int> (b+1));
        for(int i=0;i<=a;i++)
        {
            for(int j=0;j<=b;j++)
            {
                if(i==0 and j==0)
                    dp[i][j]=1;
                else if(i==0)
                    dp[i][j]=(dp[i][j-1] and s2[j-1]==s3[i+j-1]);
                else if(j==0)
                    dp[i][j]=(dp[i-1][j] and s1[i-1]==s3[i+j-1]);
                else
                    dp[i][j]=((dp[i-1][j] and s1[i-1]==s3[i+j-1]) or (dp[i][j-1] and s2[j-1]==s3[i+j-1]));
            }
        }
        return dp[a][b];
    }
};
//Approach 2: Using 1D DP
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int a=s1.size(),b=s2.size(),c=s3.size();
        if((a+b)!=c)
            return false;
        vector<int> dp(b+1);
        for(int i=0;i<=a;i++)
        {
            for(int j=0;j<=b;j++)
            {
                if(i==0 and j==0)
                    dp[j]=1;
                else if(i==0)
                    dp[j]=(dp[j-1] and s2[j-1]==s3[i+j-1]);
                else if(j==0)
                    dp[j]=(dp[j] and s1[i-1]==s3[i+j-1]);
                else
                    dp[j]=((dp[j] and s1[i-1]==s3[i+j-1]) or (dp[j-1] and s2[j-1]==s3[i+j-1]));
            }
        }
        return dp[b];
    }
};
