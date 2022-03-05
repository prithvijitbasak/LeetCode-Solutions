//Editorial: https://leetcode.com/problems/delete-and-earn/discuss/109891/Sharing-my-Simple-Straight-Forward-Java-O(n)-Solution-Explanation-Included
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> sums(10002,0);
        for(auto it:nums)
            sums[it]+=it;
        for(int i=2;i<sums.size();i++)
            sums[i]=max(sums[i-1],sums[i]+sums[i-2]);
        return sums[sums.size()-1];
    }
};
