//Editorial: https://leetcode.com/problems/132-pattern/discuss/94071/Single-pass-C++-O(n)-space-and-time-solution-(8-lines)-with-detailed-explanation.
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> stk;
        int s3=INT_MIN,n=nums.size();
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]<s3)
                return true;
            else
            {
                while(!stk.empty() and stk.top()<nums[i])
                {
                    s3=stk.top();
                    stk.pop();
                }
            }
            stk.push(nums[i]);
        }
        return false;
    }
};
