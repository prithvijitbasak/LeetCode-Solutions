//Editorial: https://leetcode.com/problems/minimum-operations-to-make-array-equal-ii/solutions/3082129/very-simple-and-easy-to-understand-solution/?orderBy=most_votes
class Solution {
public:
    typedef long long ll;
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        ll n=nums1.size();
        ll up=0,down=0;
        for(ll i=0;i<n;i++)
        {
            ll diff=abs(nums1[i]-nums2[i]);
            if(diff==0)
                continue;
            if(k==0)
                return -1;
            else if(diff%k==0)
            {
                if(nums1[i]>nums2[i])
                    down+=(diff/k);
                else
                    up+=(diff/k);
            }
            else
                return -1;
        }
        if(up==down)
            return down;
        return -1;
    }
};
