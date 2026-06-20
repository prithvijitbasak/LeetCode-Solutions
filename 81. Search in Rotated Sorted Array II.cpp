// Editorial: https://www.youtube.com/watch?v=w2G2W8l__pc
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0,high=n-1;
        while(low<=high) {
            int mid=low+(high-low)/2;
            if(nums[mid] == target)
                return true;
            if(nums[low]==nums[mid] and nums[mid]==nums[high]) {
                low+=1;
                high-=1;
                continue;
            }
            if(nums[low]<=nums[mid]) {
                if(nums[low]<=target and target<=nums[mid])
                    high=mid-1;
                else
                    low=mid+1;
            }
            else {
                if(nums[mid]<=target and target<=nums[high])
                    low=mid+1;
                else
                    high=mid-1;
            }
        }
        return false;
    }
};
