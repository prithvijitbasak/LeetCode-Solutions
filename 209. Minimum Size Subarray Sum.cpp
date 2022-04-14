//Editorial: https://leetcode.com/problems/minimum-size-subarray-sum/solution/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int left=0,sum=0;
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            while(sum>=target)
            {
                ans=min(ans,i+1-left);
                sum-=nums[left++];
            }
        }
        return ans==INT_MAX?0:ans;
    }
};
