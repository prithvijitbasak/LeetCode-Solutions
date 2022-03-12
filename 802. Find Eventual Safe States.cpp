//Editorial: https://leetcode.com/problems/find-eventual-safe-states/discuss/400205/Easy-to-understand-One-Vector-O(n)-C%2B%2B-Solution.
class Solution {
public:
    bool dfs(int node,vector<vector<int>> &graph,vector<int> &color)
    {
        color[node]=1;
        for(auto it:graph[node])
        {
            if((color[it]==0 and dfs(it,graph,color)) or color[it]==1)
                return true;
        }
        color[node]=2;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,0);
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(color[i]==2 or !dfs(i,graph,color))
                ans.push_back(i);
        }
        return ans;
    }
};
