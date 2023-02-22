//Editorial: https://youtu.be/hpF87ioNqjA
class Solution {
public:
    bool valid(vector<int> &nums,int days,int mid)
    {
        int req=1;
        int sum=0;
        for(auto it:nums)
        {
            if(sum+it<=mid)
                sum+=it;
            else
            {
                sum=it;
                req+=1;
            }
        }
        return req<=days;
    }
    int shipWithinDays(vector<int>& nums, int days) {
        int sum=0;
        for(auto it:nums)
            sum+=it;
        int maxi=*max_element(nums.begin(),nums.end());
        int low=maxi;
        int high=sum;
        int ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(valid(nums,days,mid))
            {
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};
