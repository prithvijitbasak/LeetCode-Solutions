//Editorial: It's a basic problem no effort is needed to solve it.
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            ans.push_back(nums[nums[i]]);
        }
        return ans;
    }
};
