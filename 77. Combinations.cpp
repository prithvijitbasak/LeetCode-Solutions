//Editorial: https://leetcode.com/problems/combinations/discuss/27111/My-shortest-c%2B%2B-solutionusing-dfs
class Solution {
public:
    void solve(vector<vector<int>> &ans,vector<int> &ds,int idx,int n,int k)
    {
        if(ds.size()==k)
        {
            ans.push_back(ds);
            return;
        }
        for(int i=idx;i<=n;i++)
        {
            ds.push_back(i);
            solve(ans,ds,i+1,n,k);
            ds.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(ans,ds,1,n,k);
        return ans;
    }
};
