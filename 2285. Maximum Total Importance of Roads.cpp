//Editorial: https://leetcode.com/problems/maximum-total-importance-of-roads/discuss/2083774/Node-Degree
class Solution {
public:
    typedef long long ll;
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<ll> degree(n,0);
        for(auto it:roads)
        {
            degree[it[0]]+=1;
            degree[it[1]]+=1;
        }
        ll ans=0;
        sort(degree.begin(),degree.end());
        for(int i=0;i<n;i++)
            ans+=degree[i]*(i+1);
        return ans;
    }
};
