//Editorial: https://leetcode.com/problems/count-the-number-of-fair-pairs/solutions/3174840/java-count-pairs-whose-sum-is-target-explained/?orderBy=most_votes
class Solution {
public:
    typedef long long ll;
    ll solve(vector<int> &nums,ll val)
    {
        ll l=0,r=nums.size()-1;
        ll ans=0;
        while(l<r)
        {
            ll sum=nums[l]+nums[r];
            if(sum<=val)
            {
                ans+=(r-l);
                l+=1;
            }
            else
                r-=1;
        }
        return ans;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        return solve(nums,upper)-solve(nums,lower-1);
    }
};
