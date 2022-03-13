//Editorial: https://leetcode.com/problems/shortest-path-with-alternating-colors/discuss/656384/C%2B%2B-BFS-with-explanation
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>> graph(n);
        for(auto it:redEdges)
            graph[it[0]].push_back({it[1],0});
        for(auto it:blueEdges)
            graph[it[0]].push_back({it[1],1});
        vector<int> dist(n,-1);
        queue<vector<int>> q;
        q.push(vector<int>{0,0,-1}); //node index, distance, colour of the edge
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            dist[it[0]]=(dist[it[0]]!=-1)?dist[it[0]]:it[1];
            for(auto &adj:graph[it[0]])
            {
                //Push the node to the queue only if the next edge color is different from the pervious edge color and also if we are visiting the edge for the first time.
                if(it[2]!=adj.second and adj.first!=-1){
                    q.push(vector<int>{adj.first,it[1]+1,adj.second});
                    //Update the value in the adjacency matrix to -1 to denote that the node has already been visited.
                    adj.first=-1;
                }
            }
        }
        return dist;
    }
};
