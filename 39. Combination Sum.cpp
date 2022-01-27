//Editorial: https://youtu.be/OyZFFqQtu98
class Solution {
public:
    void solve(int idx,vector<int> &arr,int target,vector<vector<int>> &ans,vector<int> &ds)
    {
        if(idx==arr.size())
        {
            if(target==0)
                ans.push_back(ds);
            return;
        }
        if(arr[idx]<=target)
        {
            ds.push_back(arr[idx]);
            solve(idx,arr,target-arr[idx],ans,ds);
            ds.pop_back();
        }
        solve(idx+1,arr,target,ans,ds);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0,arr,target,ans,ds);
        return ans;
    }
};
