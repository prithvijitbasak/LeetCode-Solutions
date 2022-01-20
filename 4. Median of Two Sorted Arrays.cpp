//Editorial: https://youtu.be/NTop3VTjmxk
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size()<nums1.size())
            return findMedianSortedArrays(nums2,nums1);
        int n1=nums1.size(),n2=nums2.size();
        int low=0;
        int high=n1;
        while(low<=high)
        {
            int cut1=(low+high)/2;
            int cut2=(n1+n2+1)/2-cut1;
            int left1=cut1==0?INT_MIN:nums1[cut1-1];
            int left2=cut2==0?INT_MIN:nums2[cut2-1];
            int right1=cut1==n1?INT_MAX:nums1[cut1];
            int right2=cut2==n2?INT_MAX:nums2[cut2];
            if(left1<=right2 and left2<=right1)
            {
                if((n1+n2)%2==0)
                    return (double)(max(left1,left2)+min(right1,right2))/2;
                else
                    return (double)max(left1,left2);
            }        
            else if(left1>right2)
                high=cut1-1;
            else
                low=cut1+1;
        }
        return 0.0;
    }
};
