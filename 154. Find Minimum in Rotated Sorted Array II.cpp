//Editorial: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/discuss/48808/My-pretty-simple-code-to-solve-it/225388
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=n-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]<nums[high])
                high=mid;
            else if(nums[mid]>nums[high])
                low=mid+1;
            else
            {
                if(high!=0 and nums[high]>=nums[high-1])
                    high--;
                else
                    return nums[high];
            }
        }
        return -1;
    }
};
