//Editorial: Just use prefix sum.
class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto it:nums)
            sum+=it;
        int leftsum=0;
        for(int i=0;i<n;i++)
        {
            if(leftsum==sum-leftsum-nums[i])
                return i;
            leftsum+=nums[i];
        }
        return -1;
    }
};
