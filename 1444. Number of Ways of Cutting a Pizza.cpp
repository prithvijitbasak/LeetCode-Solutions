//Editorial: https://youtu.be/4Jiha4IF9Mk
class Solution {
public:
    const int mod=1e9+7;
    vector<vector<vector<int>>> dp;
    vector<vector<int>> apples;
    int solve(int i,int j,int k, int r,int c)
    {
        if(apples[i][j]<k)
            return 0;
        if(k==1)
            return (apples[i][j]>=1)?1:0;
        if(dp[i][j][k]!=-1)
            return dp[i][j][k];
        dp[i][j][k]=0;
        for(int h=i+1;h<r;h++)
        {
            if(abs(apples[i][j]-apples[h][j])>0 and apples[h][j]>=k-1)
                dp[i][j][k]=(dp[i][j][k]%mod + solve(h,j,k-1,r,c)%mod)%mod;
        }
        for(int v=j+1;v<c;v++)
        {
            if(abs(apples[i][j]-apples[i][v])>0 and apples[i][v]>=k-1)
                dp[i][j][k]=(dp[i][j][k]%mod + solve(i,v,k-1,r,c)%mod)%mod;
        }
        return dp[i][j][k];
    }
    int ways(vector<string>& pizza, int k) {
        int r=pizza.size();
        int c=pizza[0].size();
        dp.resize(r,vector<vector<int>> (c,vector<int> (k+1,-1)));
        apples.resize(r,vector<int> (c,0));
        for(int i=r-1;i>=0;i--)
        {
            for(int j=c-1;j>=0;j--)
            {
                int diag=(i+1==r or j+1==c)?0:apples[i+1][j+1];
                int right=(j+1==c)?0:apples[i][j+1];
                int down=(i+1==r)?0:apples[i+1][j];
                apples[i][j]=right+down-diag+(pizza[i][j]=='A');
            }
        }
        return solve(0,0,k,r,c);
    }
};
