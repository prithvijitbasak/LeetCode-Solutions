//Editorial: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/solution/236652
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=n-1;
        while(low<high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]<nums[high])
                high=mid;
            else
                low=mid+1;
        }
        return nums[low];
    }
};
