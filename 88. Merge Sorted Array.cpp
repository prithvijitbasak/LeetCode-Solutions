//Editorial: https://leetcode.com/problems/merge-sorted-array/discuss/29515/4ms-C++-solution-with-single-loop/653088
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1,j=n-1;
        int len=m+n-1;
        while(j>=0)
        {
            if(i>=0 and nums1[i]>=nums2[j])
            {
                nums1[len]=nums1[i];
                len--;
                i--;
            }
            else
            {
                nums1[len]=nums2[j];
                len--;
                j--;
            }
        }
    }
};
