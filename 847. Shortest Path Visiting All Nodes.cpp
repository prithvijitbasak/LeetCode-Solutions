//Editorial: https://youtu.be/TmRk2F9L3Jw
class Solution {
public:
    int solve(vector<vector<int>> &graph)
    {
        queue<pair<int,pair<int,int>>> q;
        set<pair<int,int>> vis;
        int n=graph.size();
        int total=(1<<n)-1;
        for(int i=0;i<n;i++)
        {
            int mask=1<<i;
            q.push({i,{0,mask}});
            vis.insert({i,mask});
        }
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            int val=node.first,dist=node.second.first,mask=node.second.second;
            for(auto it:graph[val])
            {
                int newmask=mask|(1<<it);
                if(newmask==total)
                    return dist+1;
                else if(vis.count({it,newmask}))
                    continue;
                vis.insert({it,newmask});
                q.push({it,{dist+1,newmask}});
            }
        }
        return 0;
    }
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        if(n==1)
            return 0;
        return solve(graph);
    }
};
