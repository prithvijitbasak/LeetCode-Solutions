//Editorial: https://leetcode.com/problems/richest-customer-wealth/discuss/1732942/Java-C%2B%2B-easy-to-go-EXPLANATION
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans=INT_MIN;
        int m=accounts.size(),n=accounts[0].size();
        for(int i=0;i<m;i++)
        {
            int sum=0;
            for(int j=0;j<n;j++)
                sum+=accounts[i][j];
            ans=max(ans,sum);
        }
        return ans;
    }
};
