//Editorial: https://leetcode.com/problems/count-subarrays-with-fixed-bounds/discuss/2707995/Simple-O(n)-C++-solution
class Solution {
public:
    typedef long long ll;
    long long countSubarrays(vector<int>& nums, int mink, int maxk) {
        ll ans=0;
        int n=nums.size();
        int mins=-1,maxs=-1,start=0;
        int minf=0,maxf=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<mink or nums[i]>maxk)
            {
                minf=0;
                maxf=0;
                start=i+1;
            }
            if(nums[i]==mink)
            {
                minf=1;
                mins=i;
            }
            if(nums[i]==maxk)
            {
                maxf=1;
                maxs=i;
            }
            if(maxf and minf)
                ans+=min(maxs,mins)-start+1;
        }
        return ans;
    }
};
