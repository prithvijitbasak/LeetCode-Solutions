//Editorial: https://youtu.be/4sQL7R5ySUU
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0,high=n-1;
        vector<int> ans(2,-1);
        // for the first occurence 
        while(low<=high)
        {
            int mid=(low+high)>>1;
            if(nums[mid]==target)
            {
                ans[0]=mid;
                high=mid-1;
            }
            else if(nums[mid]<target)
                low=mid+1;
            else
                high=mid-1;
        }
        low=0,high=n-1;
        // second occurence of the target
        while(low<=high)
        {
            int mid=(low+high)>>1;
            if(nums[mid]==target)
            {
                ans[1]=mid;
                low=mid+1;
            }
            else if(nums[mid]<target)
                low=mid+1;
            else
                high=mid-1;
        }
        return ans;
    }
};
