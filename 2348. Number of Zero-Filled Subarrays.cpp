//Editorial: Just find the length of subarray having all zero and do n*(n+1)/2 formula as a array of size n have n*(n+1)/2  subarrays.
class Solution {
public:
    typedef long long ll;
    long long zeroFilledSubarray(vector<int>& nums) {
        ll ans=0;
        ll startpos=-1;
        ll n=nums.size();
        for(ll i=0;i<n;)
        {
            if(nums[i]==0)
            {
                startpos=i;
                while(i<n and nums[i]==0)
                    i+=1;
                ll len=i-startpos;
                ans+=(len*(len+1))/2;
            }
            else
                i+=1;
        }
        return ans;
    }
};
