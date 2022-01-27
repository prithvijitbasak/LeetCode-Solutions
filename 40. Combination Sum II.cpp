//Editorial: https://youtu.be/G1fRTGRxXU8
class Solution {
public:
    void solve(int idx,int target,vector<int> &arr,vector<vector<int>> &ans,vector<int> &ds)
    {
        if(target==0)
        {
            ans.push_back(ds);
            return;
        }
        for(int i=idx;i<arr.size();i++)
        {
            if(i>idx and arr[i]==arr[i-1])
                continue;
            if(arr[i]>target)
                break;
            ds.push_back(arr[i]);
            solve(i+1,target-arr[i],arr,ans,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(arr.begin(),arr.end());
        solve(0,target,arr,ans,ds);
        return ans;
    }
};
