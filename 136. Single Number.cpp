//Editorial: https://leetcode.com/problems/single-number/discuss/42997/My-O(n)-solution-using-XOR/41557
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(auto it:nums)
            ans^=it;
        return ans;
    }
};
