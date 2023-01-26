//Editorial: https://leetcode.com/problems/cheapest-flights-within-k-stops/solutions/2825208/cheapest-flights-within-k-stops/?orderBy=most_votes
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:flights)
            adj[it[0]].push_back({it[1],it[2]});
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        vector<int> dist(n,INT_MAX);
        pq.push({0,src,0});
        while(!pq.empty())
        {
            auto [cost,u,stops]=pq.top();
            pq.pop();
            if(stops>dist[u])
                continue;
            if(u==dst)
                return cost;
            if(stops>k)
                continue;
            dist[u]=stops;
            for(auto it:adj[u])
            {
                auto [v,w]=it;
                pq.push({cost+w,v,stops+1});
            }
        }
        return -1;
    }
};
