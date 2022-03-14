//Editorial: https://youtu.be/nbgaEu-pvkU
class Solution {
public:
    bool check(vector<vector<int>> &adj,vector<int> &color,int src)
    {
        color[src]=1;
        queue<int> q;
        q.push(src);
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it:adj[node])
            {
                if(color[it]==-1)
                {
                    color[it]=1-color[node];
                    q.push(it);
                }
                else if(color[it]==color[node])
                    return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> color(n+1,-1);
        vector<vector<int>> adj(n+1);
        for(auto it:dislikes)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(!check(adj,color,i))
                    return false;
            }
        }
        return true;
    }
};
