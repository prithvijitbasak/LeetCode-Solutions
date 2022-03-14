//Editorial: https://leetcode.com/problems/maximal-network-rank/discuss/888916/Java-simple-O(n2)
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n,0);
        vector<vector<int>> adj(n,vector<int> (n,0));
        for(auto it:roads)
        {
            degree[it[0]]+=1;
            degree[it[1]]+=1;
            adj[it[0]][it[1]]=1;
            adj[it[1]][it[0]]=1;
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                ans=max(ans,degree[i]+degree[j]-(adj[i][j]?1:0));
            }
        }
        return ans;
    }
};
