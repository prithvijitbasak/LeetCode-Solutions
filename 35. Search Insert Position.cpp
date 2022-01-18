//Editorial: https://leetcode.com/problems/search-insert-position/discuss/15101/C%2B%2B-O(logn)-Binary-Search-that-handles-duplicate
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]<target)
                low=mid+1;
            else
                high=mid-1;
        }
        return low;
    }
};
