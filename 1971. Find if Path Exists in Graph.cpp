//Editorial: Just do normal bfs.
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source==destination)
            return true;
        vector<int> adj[n];
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        queue<int> q;
        q.push(source);
        vis[source]=1;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it:adj[node])
            {
                if(it==destination)
                    return true;
                if(!vis[it])
                {
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        return false;
    }
};
