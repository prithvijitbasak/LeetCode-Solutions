//Editorial: Go through the code thoroughly.
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int,int> ump;
        for(auto it:nums)
        {
            // here the intuition is for every |x|
            // mathematically we can write +x and -x
            // thereby for |nums[i] - nums[j]|
            // we can write +(nums[i] - nums[j]) and -(nums[i] - nums[j])
            // now think it as -(x-y) = k
            // and +(x-y) = k
            // and we can write it as (y = x + k) and (y = x - k)
            ans += (ump[it-k] + ump[it+k]);

            // and here the map must be updated on the go because
            // there might be a pair that can be made where j>i
            // so the map should be made on the go instead of before hand.
            ump[it] += 1;
        }
        return ans;
    }
};
