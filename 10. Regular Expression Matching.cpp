//Editorial: https://youtu.be/HAA8mgxlov8, https://leetcode.com/problems/regular-expression-matching/discuss/751381/Brute-force-to-top-down-DP-and-bottom-up-DP-with-explanation
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length()+1,vector<int> (p.length(),-1));
        return mem(s,p,0,0,dp);
    }
    bool mem(string s,string p,int i,int j,vector<vector<int>> &dp)
    {
        if(j==p.length())
            return i==s.length();
        if(dp[i][j]>=0)
            return dp[i][j];
        bool first_match=(i<s.length() and (s[i]==p[j] or p[j]=='.'));
        bool total=0;
        if(j+1<p.length() and p[j+1]=='*')
            total=(mem(s,p,i,j+2,dp) or (first_match and mem(s,p,i+1,j,dp)));
        else
            total=(first_match and mem(s,p,i+1,j+1,dp));
        return dp[i][j]=total;
    }
};
