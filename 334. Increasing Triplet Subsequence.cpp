//Editorial: https://youtu.be/90tYQ5jNVPo
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        int left=INT_MAX,mid=INT_MAX; // we are storing the left boundaries of 1st and the 2nd element.
        for(int i=0;i<n;i++)
        {
            if(nums[i]<=left)
                left=nums[i];
            else if(nums[i]<=mid)
                mid=nums[i];
            else
                return true;
        }
        return false;
    }
};
