//Editorial: https://youtu.be/dJ7sWiOoK7g, https://leetcode.com/problems/jump-game-ii/discuss/1192401/Easy-Solutions-w-Explanation-or-Optimizations-from-Brute-Force-to-DP-to-Greedy-BFS
class Solution {
public:
    int jump(vector<int>& nums) {
        int i=0,lastjumppos=0,maxreach=0,jumps=0;
        int n=nums.size();
        while(lastjumppos<n-1)
        {
            maxreach=max(maxreach,i+nums[i]);
            if(i==lastjumppos)
            {
                lastjumppos=maxreach;
                jumps++;
            }
            i++;
        }
        return jumps;
    }
};
