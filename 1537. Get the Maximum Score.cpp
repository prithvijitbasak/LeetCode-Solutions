//Editorial: https://leetcode.com/problems/get-the-maximum-score/discuss/767987/JavaC++Python-Two-Pointers-O(1)-Space/639504
class Solution {
public:
    typedef long long int ll;
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        ll mod=1e9+7;
        ll sum1=0,sum2=0;
        ll i=0,j=0,m=nums1.size(),n=nums2.size();
        ll ans=0;
        while(i<m and j<n)
        {
            if(nums1[i]<nums2[j])
            {
                sum1+=nums1[i];
                i+=1;
            }
            else if(nums2[j]<nums1[i])
            {
                sum2+=nums2[j];
                j+=1;
            }
            else
            {
                ans+=max(sum1,sum2)+nums1[i];
                i+=1;
                j+=1;
                sum1=0;
                sum2=0;
            }
        }
        while(i<m)
        {
            sum1+=nums1[i];
            i+=1;
        }
        while(j<n)
        {
            sum2+=nums2[j];
            j+=1;
        }
        ans=(max(sum1,sum2)+ans)%mod;
        return ans;
    }
};
