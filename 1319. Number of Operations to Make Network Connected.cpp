//Approach 1: Using dsu 
//Editorial: https://leetcode.com/problems/number-of-operations-to-make-network-connected/discuss/618686/C%2B%2B-or-Union-Find-or-Connected-components
class Solution {
public:
    vector<int> parent;
    int findparent(int i)
    {
        if(parent[i]==i)
            return i;
        return parent[i]=findparent(parent[i]);
    }
    int makeConnected(int n, vector<vector<int>>& grid) {
        int c=grid.size();
        if(c<n-1)
            return -1;
        parent.resize(n);
        for(int i=0;i<n;i++)
            parent[i]=i;
        for(int i=0;i<c;i++)
        {
            int x=findparent(grid[i][0]);
            int y=findparent(grid[i][1]);
            if(x!=y)
                parent[y]=x;
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(parent[i]==i)
                ans+=1;
        }
        return ans-1;
    }
};
//Approach 2: Using redundant edge concept.
//Editorial: https://youtu.be/3JIwIRir2sM
class Solution {
    public:
    void dfs(vector<int> adj[],int node,vector<int> &vis)
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
                dfs(adj,it,vis);
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        vector<int> vis(n,0);
        int edges=0;
        for(int i=0;i<connections.size();i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
            edges++;
        }
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                c+=1;
                dfs(adj,i,vis);
            }
        }
        if(edges<n-1)
            return -1;
        int red=edges-((n-1)-(c-1));
        if(red>=(c-1))
            return c-1;
        else
            return c-1;
    }
};
