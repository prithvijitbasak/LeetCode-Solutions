//Editorial: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/solution/
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int l=n,r=0;
        int mini=INT_MAX,maxi=INT_MIN;
        int f=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]<nums[i-1])
                f=1;
            if(f)
                mini=min(nums[i],mini);
        }
        f=0;
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]>nums[i+1])
                f=1;
            if(f)
                maxi=max(maxi,nums[i]);
        }
        for(int i=0;i<n;i++)
        {
            if(mini<nums[i])
            {
                l=i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(maxi>nums[i])
            {
                r=i;
                break;
            }
        }
        return r-l<0?0:r-l+1;
    }
};
