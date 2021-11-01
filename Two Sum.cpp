//Editorial link: https://leetcode.com/problems/two-sum/discuss/674/C%2B%2B-one-pass
//Code:
//Runtime: 12ms 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        if(nums.size()==0)
            return ans;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(target-nums[i])!=mp.end())
            {
                ans.push_back(mp[target-nums[i]]);
                ans.push_back(i);
            }
            mp[nums[i]]=i;
        }
        return ans;
    }
};
