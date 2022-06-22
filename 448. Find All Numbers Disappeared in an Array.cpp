//Editorial: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/discuss/1583736/C++Python-All-6-Solutions-w-Explanations-or-Binary-Search+-Hashset-+-2x-O(1)-Space-Approach
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int idx=abs(nums[i])-1;
            nums[idx]=(nums[idx]>0)?-nums[idx]:nums[idx];
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
                ans.push_back(i+1);
        }
        return ans;
    }
};
