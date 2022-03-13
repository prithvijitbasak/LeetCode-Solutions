//Editorial: https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/discuss/827414/straightforward-c%2B%2B-solution-oror-bfs
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        int ans=0;
        vector<vector<int>> adj(n),back(n);
        for(auto it:connections)
        {
            adj[it[0]].push_back(it[1]);
            back[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        queue<int> q;
        q.push(0);
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            vis[node]=1;
            for(auto it:adj[node])
            {
                if(!vis[it])
                {
                    ans+=1;
                    q.push(it);
                }        
            }
            for(auto it:back[node])
            {
                if(!vis[it])
                    q.push(it);
            }
        }
        return ans;
    }
};
