//Editorial: https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/discuss/754682/Wall-of-bricks
class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n=target.size();
        int ans=target[0];
        for(int i=1;i<n;i++)
            ans+=max(target[i]-target[i-1],0);
        return ans;
    }
};
