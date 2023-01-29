//Editorial: https://leetcode.com/problems/put-marbles-in-bags/solutions/3111642/simple-c-solution-using-sort-idea-explained/?orderBy=most_votes
class Solution {
public:
    typedef long long ll;
    long long putMarbles(vector<int>& weights, int k) {
        vector<ll> nums;
        ll n=weights.size();
        for(ll i=0;i<n-1;i++)
            nums.push_back(weights[i]+weights[i+1]);
        sort(nums.begin(),nums.end());
        ll maxval=0,minval=0;
        for(ll i=0;i<k-1;i++)
        {
            minval+=nums[i];
            maxval+=nums[n-2-i];
        }
        return maxval-minval;
    }
};
