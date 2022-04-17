//Editorial: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/discuss/446376/JavaC%2B%2BPython-Binary-Search
class Solution {
public:
    bool solve(vector<int> nums,int div,int k)
    {
        int sum=0;
        for(auto it:nums)
            sum+=(it/div)+(it%div!=0);
        if(sum<=k)
            return true;
        else
            return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int low=1,high=1e6;
        while(low<high)
        {
            int mid=low+(high-low)/2;
            if(!solve(nums,mid,threshold))
                low=mid+1;
            else
                high=mid;
        }
        return low;
    }
};
