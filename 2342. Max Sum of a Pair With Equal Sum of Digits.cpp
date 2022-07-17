//Editorial: https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/discuss/2292858/FIRST-TWO-OF-SAME-KEY-oror-Intuition
class Solution {
public:
    int getsum(int n)
    {
        int sum=0;
        while(n)
        {
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.rbegin(),nums.rend());
        map<int,vector<int>> mp;
        for(auto it:nums)
            mp[getsum(it)].push_back(it);
        int ans=0;
        for(auto &[it,arr]:mp)
        {
            if(arr.size()>=2)
                ans=max(ans,arr[0]+arr[1]);
        }
        return ans==0?-1:ans;
    }
};
