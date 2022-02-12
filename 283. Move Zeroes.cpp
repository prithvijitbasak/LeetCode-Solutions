//Editorial: https://leetcode.com/problems/move-zeroes/discuss/72005/My-simple-C%2B%2B-solution
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
                nums[j++]=nums[i];
        }
        for(;j<nums.size();j++)
            nums[j]=0;
    }
};
