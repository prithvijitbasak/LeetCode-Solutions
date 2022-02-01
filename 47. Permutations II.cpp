//Editorial: https://leetcode.com/problems/permutations-ii/discuss/18596/A-simple-C%2B%2B-solution-in-only-20-lines
class Solution {
public:
    void solve(int i,int j,vector<int> nums,vector<vector<int>> &ans)
    {
        if(i==j-1)
        {
            ans.push_back(nums);
            return;
        }
        for(int k=i;k<j;k++)
        {
            if(i!=k and nums[i]==nums[k])
                continue;
            swap(nums[i],nums[k]);
            solve(i+1,j,nums,ans);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        solve(0,nums.size(),nums,ans);
        return ans;
    }
};
