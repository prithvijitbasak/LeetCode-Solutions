//Editorial: https://leetcode.com/problems/all-paths-from-source-to-target/discuss/752625/C%2B%2B-DFS-based-Simple-Solution-Explained-100-Time-~80-Space
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    int target;
    void dfs(vector<vector<int>> &graph,int curr){
        temp.push_back(curr);
        if(curr==target)
            ans.push_back(temp);
        for(auto it:graph[curr])
            dfs(graph,it);
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        target=n-1;
        dfs(graph,0);
        return ans;
    }
};
