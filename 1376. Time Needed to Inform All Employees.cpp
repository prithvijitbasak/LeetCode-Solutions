//Editorial: https://leetcode.com/problems/time-needed-to-inform-all-employees/discuss/532487/C%2B%2B-DFS, https://youtu.be/7K9XW8KpHP0
class Solution {
public:
    vector<vector<int>> adj;
    int dfs(int node,vector<int> &informTime)
    {
        int time=0;
        for(auto it:adj[node])
            time=max(time,dfs(it,informTime));
        return time+informTime[node];
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        adj.resize(n);
        for(int i=0;i<manager.size();i++)
        {
            if(manager[i]!=-1)
                adj[manager[i]].push_back(i);
        }
        return dfs(headID,informTime);
    }
};
