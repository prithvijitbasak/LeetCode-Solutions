//Editorial: https://leetcode.com/problems/minimum-time-to-complete-trips/editorial/
class Solution {
public:
    typedef long long ll;
    bool valid(vector<int> nums,ll mid,int tt)
    {
        ll sum=0;
        for(auto it:nums)
            sum+=mid/it;
        return sum>=tt;
    }
    long long minimumTime(vector<int>& time, int tt) {
        ll low=1;
        ll high=1LL* *max_element(time.begin(),time.end())*tt;
        while(low<high)
        {
            ll mid=low+(high-low)/2LL;
            if(valid(time,mid,tt))
                high=mid;
            else
                low=mid+1;
        }
        return low;
    }
};
