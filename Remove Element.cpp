//Editorial: https://leetcode.com/problems/remove-element/discuss/1048331/C-C%2B%2B.-0-ms-faster-than-100.00.-cool-clear-and-easy-solution.
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len=nums.size();
        int idx=0;
        while(idx<len)
        {
            if(nums[idx]==val)
                nums[idx]=nums[len-1],len--;
            else
                idx++;
        }
        return len;
    }
};
