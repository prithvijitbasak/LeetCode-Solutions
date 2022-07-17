//Editorial: https://leetcode.com/problems/maximum-number-of-pairs-in-array/discuss/2292669/Divide-and-Mod
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int n=nums.size();
        map<int,int> mp;
        for(auto it:nums)
            mp[it]+=1;
        int pair=0;
        for(auto it:mp)
        {
            pair+=it.second/2;
        }
        int left=abs(n-(2*pair));
        return vector<int> {pair,left};
    }
};
