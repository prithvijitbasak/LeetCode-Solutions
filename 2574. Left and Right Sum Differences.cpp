//Editorial: Just use the normal prefix sum.
class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int> pre=nums;
        for(int i=1;i<n;i++)
            pre[i]+=pre[i-1];
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            int left=(i==0)?0:pre[i-1];
            int right=(i==n-1)?0:pre[n-1]-pre[i];
            ans[i]=abs(left-right);
        }
        return ans;
    }
};
