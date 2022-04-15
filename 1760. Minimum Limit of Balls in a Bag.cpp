//Editorial: https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/discuss/1064548/JavaC%2B%2BPython-Binary-Search
class Solution {
public:
    int minimumSize(vector<int>& nums, int k) {
        int low=1,high=*max_element(nums.begin(),nums.end());
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int cnt=0;
            for(auto it:nums)
                cnt+=(it-1)/mid;
            if(cnt>k)
                low=mid+1;
            else
                high=mid-1;
        }
        return low;
    }
};
