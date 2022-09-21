//Editorial: https://leetcode.com/problems/sum-of-even-numbers-after-queries/discuss/2603372/LeetCode-The-Hard-Way-Explained-Line-By-Line
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum=0;
        vector<int> ans;
        for(auto it:nums)
        {
            if(it%2==0)
                sum+=it;
        }
        for(auto it:queries)
        {
            int val=it[0];
            int idx=it[1];
            if(nums[idx]%2==0)
                sum-=nums[idx];
            nums[idx]+=val;
            if(nums[idx]%2==0)
                sum+=nums[idx];
            ans.push_back(sum);
        }
        return ans;
    }
};
