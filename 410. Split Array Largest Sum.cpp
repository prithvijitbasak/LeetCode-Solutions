//Editorial: https://youtu.be/YUF3_eBdzsk
class Solution {
public:
    int check(vector<int> &nums,int maxsum)
    {
        int cntsub=0;
        int currsum=0;
        for(auto it:nums)
        {
            if(currsum+it<=maxsum)
                currsum+=it;
            else
            {
                currsum=it;
                cntsub+=1;
            }
        }
        return cntsub+1;
    }
    int splitArray(vector<int>& nums, int m) {
        int sum=0;
        int low=*max_element(nums.begin(),nums.end());
        int high;
        for(auto it:nums)
            sum+=it;
        high=sum;
        int ans;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(check(nums,mid)<=m)
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
