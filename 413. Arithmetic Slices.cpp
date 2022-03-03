//Approach 1: Using bottom-up dp TC: O(n) SC: O(n)
//Editorial: https://leetcode.com/problems/arithmetic-slices/discuss/90093/3ms-C++-Standard-DP-Solution-with-Very-Detailed-Explanation/94651
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<3)
            return 0;
        vector<int> dp(n,0);
        int ans=0;
        for(int i=2;i<n;i++)
        {
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2])
                dp[i]=dp[i-1]+1;
            ans+=dp[i];
        }
        return ans;
    }
};
//Approach 2: Using bottom-up dp with space optimisation. TC: O(n) SC: O(1)
//Editorial: https://leetcode.com/problems/arithmetic-slices/discuss/90093/3ms-C++-Standard-DP-Solution-with-Very-Detailed-Explanation/94649
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<3)
            return 0;
        int temp=0,ans=0;
        for(int i=2;i<n;i++)
        {
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2])
                temp+=1;
            else
                temp=0;
            ans+=temp;
        }
        return ans;
    }
};
