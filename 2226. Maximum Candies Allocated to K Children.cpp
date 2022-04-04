//Editorial: https://leetcode.com/problems/maximum-candies-allocated-to-k-children/discuss/1908738/C%2B%2B-Easy-solution-with-Explanation
class Solution {
public:
    typedef long long ll;
    int solve(vector<int> nums,ll mid,ll k)
    {
        ll cnt=0;
        for(auto it:nums)
        {
            cnt+=it/mid;
            if(cnt>=k)
                return 1;
        }
        return 0;
        
    }
    int maximumCandies(vector<int>& nums, long long k) {
        int low=1,high=*max_element(nums.begin(),nums.end());
        int ans=0;
        while(low<=high)
        {
            ll mid=low+(high-low)/2;
            if(solve(nums,mid,k))
            {
                ans=mid;
                low=mid+1;
            }
            else
                high=mid-1;
        }
        return ans;
    }
};
