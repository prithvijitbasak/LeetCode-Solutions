//Editorial: https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/editorial
//Approach 1: Using DFS.
class Solution {
public:
    typedef long long ll;
    ll dfs(vector<ll> adj[],vector<ll> &vis,ll node)
    {
        ll cnt=1;
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
                cnt+=dfs(adj,vis,it);
        }
        return cnt;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        ll ans=0;
        vector<ll> adj[n];
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        ll remnodes=n;
        ll soc=0;
        vector<ll> vis(n,0);
        for(ll i=0;i<n;i++)
        {
            if(!vis[i])
            {
                soc=dfs(adj,vis,i);
                ans+=soc*(remnodes-soc);
                remnodes-=soc;
            }
        }
        return ans;
    }
};
