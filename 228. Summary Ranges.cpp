//Editorial: https://leetcode.com/problems/summary-ranges/discuss/63284/10-line-c%2B%2B-easy-understand
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n=nums.size();
        for(int i=0;i<nums.size();)
        {
            int start=i;
            int end=i;
            while(end+1<n and nums[end+1]==nums[end]+1)
                end+=1;
            if(end>start)
                ans.push_back(to_string(nums[start])+"->"+to_string(nums[end]));
            else
                ans.push_back(to_string(nums[start]));
            i=end+1;
        }
        return ans;
    }
};
