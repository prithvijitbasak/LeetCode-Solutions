//Editorial: https://leetcode.com/problems/append-k-integers-with-minimal-sum/discuss/1823619/C%2B%2B-Sorting-O(NlogN)-time
class Solution {
public:
    typedef long long ll;
    long long minimalKSum(vector<int>& nums, int k) {
        ll ans=0;
        sort(nums.begin(),nums.end());
        ll n=nums.size();
        for(int i=0;i<n and k;i++)
        {
            ll prev=(i==0)?0:nums[i-1];
            ll cnt=min((ll)k,max(0LL,nums[i]-prev-1));
            ll sum=((prev+1+prev+cnt)*cnt)/2;
            k-=cnt;
            ans+=sum;
        }
        if(k>0)
            ans+=(((ll)nums.back()+1+(ll)nums.back()+k)*k)/2;
        return ans;
    }
};
