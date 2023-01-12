//Editorial: https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/solutions/2864718/number-of-nodes-in-the-sub-tree-with-the-same-label/?orderBy=most_votes
class Solution {
public:
    vector<int> dfs(int node,int parent,vector<int> adj[],string &labels,vector<int> &ans)
    {
        vector<int> nodevals(26);
        nodevals[labels[node]-'a']=1;
        for(auto it:adj[node])
        {
            if(it==parent)
                continue;
            vector<int> childvals=dfs(it,node,adj,labels,ans);
            for(int i=0;i<26;i++)
                nodevals[i]+=childvals[i];
        }
        ans[node]=nodevals[labels[node]-'a'];
        return nodevals;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> adj[n];
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> ans(n);
        dfs(0,-1,adj,labels,ans);
        return ans;
    }
};
