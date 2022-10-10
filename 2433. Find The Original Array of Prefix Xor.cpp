//Editorial: https://leetcode.com/problems/find-the-original-array-of-prefix-xor/discuss/2678904/JavaC++Python-Easy-and-Concise-with-Explantion
class Solution {
public:
    vector<int> findArray(vector<int>& nums) {
        int n=nums.size();
        for(int i=n-1;i>0;i--)
            nums[i]^=nums[i-1];
        return nums;
    }
};
