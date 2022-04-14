//Editorial: https://leetcode.com/problems/maximum-distance-between-a-pair-of-values/discuss/1199036/7-Line-c++-or-Binary-Search-or-STL/1093250
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int m=nums2.size();
        int ans=0;
        int n=nums1.size();
        for(int i=0;i<n;i++){
            int j= lower_bound(nums2.rbegin(),nums2.rend(),nums1[i])-nums2.rbegin();
            ans=max(ans,m-j-1-i);
        }
        return ans;
    }
};
