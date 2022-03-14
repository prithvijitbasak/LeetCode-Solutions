//Editorial: https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/discuss/805685/JavaC%2B%2BPython-Nodes-with-no-In-Degree
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n,0);
        for(auto it:edges)
            indegree[it[1]]+=1;
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
                ans.push_back(i);
        }
        return ans;
    }
};
