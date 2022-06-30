//Editorial: https://leetcode.com/problems/maximum-score-of-spliced-array/discuss/2198138/Kadane/1456033
class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int sum1=0,sum2=0;
        for(auto it:nums1)
            sum1+=it;
        for(auto it:nums2)
            sum2+=it;
        int f=0,s=0,max1=0,max2=0,n=nums1.size();
        for(int i=0;i<n;i++)
        {
            f+=(nums2[i]-nums1[i]);
            s+=(nums1[i]-nums2[i]);
            max1=max(max1,f);
            max2=max(max2,s);
            if(f<0)
                f=0;
            if(s<0)
                s=0;
        }
        return max(sum1+max1,sum2+max2);
    }
};
