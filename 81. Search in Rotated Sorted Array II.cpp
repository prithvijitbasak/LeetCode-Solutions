//Approach 1: TC: O(n) (At worst case and at average case it is O(logn)). SC: O(1).
//Editorial: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/solution/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0,high=n-1;
        while(low<=high)
        {
            while(low<high and nums[low]==nums[low+1])
                low+=1;
            while(low<high and nums[high]==nums[high-1])
                high-=1;
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
                return true;
            if(nums[low]<=nums[mid])
            {
                if(nums[low]<=target and target<=nums[mid])
                    high=mid-1;
                else
                    low=mid+1;
            }
            else
            {
                if(nums[mid]<=target and target<=nums[high])
                    low=mid+1;
                else
                    high=mid-1;
            }
        }
        return false;
    }
};
//Approach 1: TC: O(logn) and SC: O(1)
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0,high=n-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
                return true;
            if(nums[low]<nums[mid])
            {
                if(nums[low]<=target and target<=nums[mid])
                    high=mid-1;
                else
                    low=mid+1;
            }
            else if(nums[low]>nums[mid])
            {
                if(nums[mid]<=target and target<=nums[high])
                    low=mid+1;
                else
                    high=mid-1;
            }
            else
                low+=1;
        }
        return false;
    }
};
