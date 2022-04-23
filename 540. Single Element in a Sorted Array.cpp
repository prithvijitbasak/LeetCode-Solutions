//Editorial: https://leetcode.com/problems/single-element-in-a-sorted-array/discuss/627921/Java-or-C++-or-Python3-or-Easy-explanation-or-O(logn)-or-O(1)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans=0,n=nums.size();
        int low=0,high=n-1;
        while(low<high)
        {
            int mid=low+(high-low)/2;
            if(((mid&1) and nums[mid]==nums[mid-1]) or ((mid%2==0 and nums[mid]==nums[mid+1])))
                low=mid+1;
            else
                high=mid;
        }
        return nums[low];
    }
};
