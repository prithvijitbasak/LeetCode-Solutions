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
//Approach 2: Using conventional technique.
//Editorial: https://leetcode.com/problems/single-number-ii/solutions/43313/a-general-c-solution-for-these-type-problems/?orderBy=most_votes
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bits(32,0);
        for(auto it:nums)
        {
            int val=it;
            for(int i=0;i<32;i++)
            {
                bits[i]+=(val&1);
                val>>=1;
                if(!val)
                    break;
            }
        }
        int ans=0;
        for(int i=0;i<32;i++)
        {
            int rem=bits[i]%3;
            if(rem)
                ans+=(1<<i);
        }
        return ans;
    }
};
