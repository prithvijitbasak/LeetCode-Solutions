// Editorial: https://www.youtube.com/watch?v=nhEMDKMB44g&t=260s 
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=n-1;
        int ans=INT_MAX;
        while(low<=high) {
            int mid=low+(high-low)/2;
            if(nums[low] <= nums[mid]) {
                ans=min(nums[low],ans);
                low=mid+1;
            }
            else
            {
                ans=min(ans,nums[mid]);
                high=mid-1;
            }
        }
        return ans;
    }
};
