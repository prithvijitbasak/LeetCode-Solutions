//Editorial: https://leetcode.com/problems/minimum-absolute-sum-difference/discuss/1141337/Short-and-Easy-w-Explanation-or-Binary-Search-solution
class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        set<int> st(nums1.begin(),nums1.end());
        long originaldiff=0,maxdiff=0;
        int n=nums1.size();
        for(int i=0;i<n;i++)
        {
            long currdiff=abs(nums1[i]-nums2[i]);
            originaldiff+=currdiff;
            auto it=st.lower_bound(nums2[i]);
            if(it!=begin(st))
                maxdiff = max(maxdiff, currdiff - abs(*prev(it) - nums2[i]));
            if(it!=end(st))
                maxdiff=max(maxdiff,currdiff-abs(*it-nums2[i]));
        }
        return (originaldiff-maxdiff)%1000000007;
    }
};
