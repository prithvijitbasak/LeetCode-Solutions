//Editorial: https://leetcode.com/problems/jump-game-vi/discuss/1260737/Optimizations-from-Brute-Force-to-Dynamic-Programming-w-Explanation
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<int> dq;
        int n=nums.size();
        dq.push_back(0);
        vector<int> dp(n);
        dp[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            if(dq.front()<i-k)
                dq.pop_front();
            dp[i]=nums[i]+dp[dq.front()];
            while(!dq.empty() and dp[dq.back()]<=dp[i])
                dq.pop_back();
            dq.push_back(i);
        }
        return dp.back();
    }
};
