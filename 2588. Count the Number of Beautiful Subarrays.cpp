//Editorial: https://leetcode.com/problems/count-the-number-of-beautiful-subarrays/solutions/3286861/c-easy-prefix-xor/?orderBy=most_votes
class Solution {
public:
    typedef long long ll;
    long long beautifulSubarrays(vector<int>& nums) {
        // here we will have to find the subarray with xor value as 0 because the number of set bits in the same place will always be even so the xor of the whole subarray will be always equal to 0.
        ll ans=0;
        unordered_map<ll,ll> ump;
        ll sum=0;
        ump[0]=1;
        for(auto it:nums)
        {
            sum^=it;
            ans+=ump[sum]; // we are just finding if there was any previous xor with same value as sum which will denote the total xor of subarray is 0.
            ump[sum]+=1;
        }
        return ans;
    }
};
