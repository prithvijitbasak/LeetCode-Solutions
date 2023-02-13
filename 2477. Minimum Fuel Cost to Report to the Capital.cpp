//Editorial: https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/solutions/3080167/minimum-fuel-cost-to-report-to-the-capital/?orderBy=most_votes
class Solution {
public:
    typedef long long ll;
    ll fuel=0;
    ll dfs(ll node,ll parent,vector<ll> adj[],int &seats)
    {
        ll rep=1;
        for(auto it:adj[node])
        {
            if(it!=parent)
                rep+=dfs(it,node,adj,seats);
        }
        if(node!=0)
            fuel+=ceil((double)rep/seats);
        return rep;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        ll n=roads.size();
        vector<ll> adj[n+1];
        for(auto it:roads)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs(0,-1,adj,seats);
        return fuel;
    }
};
