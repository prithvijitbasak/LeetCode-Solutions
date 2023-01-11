//Editorial: https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/solutions/2864715/minimum-time-to-collect-all-apples-in-a-tree/?orderBy=most_votes
class Solution {
public:
    int dfs(int node, int parent, vector<int> adj[], vector<bool> &hasApple)
    {
        int totaltime=0,childtime=0;
        for(auto child:adj[node])
        {
            if(child==parent)
                continue;
            childtime=dfs(child,node,adj,hasApple);
            if(childtime or hasApple[child])
                totaltime+=childtime+2;
        }
        return totaltime;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> adj[n];
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        return dfs(0,-1,adj,hasApple);
    }
};
