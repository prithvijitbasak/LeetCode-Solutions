//Editorial: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/discuss/686237/C++-Binary-search
class Solution {
public:
    int solve(vector<int> nums,int mid,int k)
    {
        int n=nums.size();
        int res=0,cnt=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<=mid)
                cnt+=1;
            else
                cnt=0;
            if(cnt==k)
            {
                res+=1;
                cnt=0;
            }
        }
        return res;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        auto it=minmax_element(bloomDay.begin(),bloomDay.end());
        int low=*it.first,high=*it.second;
        while(low<high)
        {
            int mid=low+(high-low)/2;
            if(solve(bloomDay,mid,k)<m)
                low=mid+1;
            else
                high=mid;
        }
        return solve(bloomDay,low,k)>=m?low:-1;
    }
};
