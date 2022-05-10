//Editorial: https://leetcode.com/problems/combination-sum-iii/discuss/60621/My-C++-solution-backtracking
class Solution {
public:
    void solve(vector<vector<int>> &ans,vector<int> &ds,int k,int n)
    {
        if(ds.size()==k and n==0)
        {
            ans.push_back(ds);
            return;
        }
        for(int i=ds.empty()?1:ds.back()+1;i<=9;i++)
        {
            ds.push_back(i);
            solve(ans,ds,k,n-i);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(ans,ds,k,n);
        return ans;
    }
};
