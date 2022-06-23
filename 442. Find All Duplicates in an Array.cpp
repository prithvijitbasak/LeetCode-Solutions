//Editorial: https://leetcode.com/problems/find-all-duplicates-in-an-array/discuss/775798/c++-Four-Solution-or-O-(N*N)-to-greater-O(N)-or-Explain-All
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(nums[abs(nums[i])-1]<0)
                ans.push_back(abs(nums[i]));
            nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
        }
        return ans;
    }
};
