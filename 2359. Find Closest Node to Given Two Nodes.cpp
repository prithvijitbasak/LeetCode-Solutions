//Editorial: https://leetcode.com/problems/find-closest-node-to-given-two-nodes/solutions/2864716/find-closest-node-to-given-two-nodes/?orderBy=most_votes
class Solution {
public:
    void bfs(int node,vector<int> &edges,vector<int> &dist)
    {
        int n=edges.size();
        vector<int> vis(n,0);
        queue<int> q;
        q.push(node);
        // vis[node]=1;
        dist[node]=0;
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            if(vis[curr])
                continue;
            vis[curr]=1;
            int next=edges[curr];
            if(next!=-1 and !vis[next])
            {
                q.push(next);
                dist[next]=1+dist[curr];
            }
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int> dist1(n,INT_MAX);
        vector<int> dist2(n,INT_MAX);
        bfs(node1,edges,dist1);
        bfs(node2,edges,dist2);
        int temp=INT_MAX;
        int ans=-1;
        for(int i=0;i<n;i++)
        {
            if(temp>max(dist1[i],dist2[i]))
            {
                ans=i;
                temp=max(dist1[i],dist2[i]);
            }
        }
        return ans;
    }
};
