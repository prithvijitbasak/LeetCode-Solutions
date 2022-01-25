//Editorial: https://youtu.be/r3pMQ8-Ad5s
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        while(low<=high)
        {
            int mid=(low+high)>>1;
            if(nums[mid]==target)
                return mid;
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
        return -1;
    }
};
