//Editorial: https://leetcode.com/problems/minimum-moves-to-equal-array-elements/discuss/93817/It-is-a-math-question/98131
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int mini=INT_MAX;
        for(auto it:nums)
        {
            sum+=it;
            mini=min(mini,it);
        }
        return sum-(n*mini);
    }
};
