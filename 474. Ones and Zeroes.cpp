//Editorial: https://leetcode.com/problems/ones-and-zeroes/discuss/814077/Dedicated-to-Beginners
class Solution {
public:
    int dp[601][101][101]={};
    int solve(vector<pair<int,int>> &arr,int m,int n,int idx)
    {
        int sz=arr.size();
        if(idx==sz or (m==0 and n==0))
            return 0;
        if(dp[idx][m][n]!=-1)
            return dp[idx][m][n];
        if(arr[idx].first>m or arr[idx].second>n)
            return dp[idx][m][n]=solve(arr,m,n,idx+1);
        int include=1+solve(arr,m-arr[idx].first,n-arr[idx].second,idx+1);
        int exclude=solve(arr,m,n,idx+1);
        return dp[idx][m][n]=max(exclude,include);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>> arr;
        for(auto it:strs)
        {
            int one=0,zero=0;
            for(auto ch:it)
            {
                if(ch=='0')
                    zero+=1;
                else
                    one+=1;
            }
            arr.push_back({zero,one});
        }
        memset(dp,-1,sizeof(dp));
        int ans=solve(arr,m,n,0);
        return ans;
    }
};
