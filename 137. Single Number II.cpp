//Approach 1: The most optimal approach using bit-manipulation.
//Editorial: https://youtu.be/cOFAmaMBVps
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones=0,twos=0;
        for(auto it:nums)
        {
            ones=(ones^it)&(~twos);
            twos=(twos^it)&(~ones);
        }
        return ones;
    }
};
