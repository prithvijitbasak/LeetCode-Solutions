//Editorial: https://youtu.be/5SrTJ4D9hKw
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        int start=1,end=1;
        string res="";
        if(n==0)
            return res;
        for(int i=0;i<=n;i++)
        {
            dp[0][i]=1;
            dp[1][i]=1;
        }
        for(int i=2;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                if(s[j-1] == s[j-i] and dp[i-2][j-1]==1)
                   {
                dp[i][j]=1;
                    start=i;
                    end=j;
                }
                else
                    dp[i][j]=0;
            }
        }        
        for(int i=end-start+1;i<=end;i++)
            res.push_back(s[i-1]);
        return res;
    }
};
