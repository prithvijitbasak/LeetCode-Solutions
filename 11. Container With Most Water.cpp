//Editorial: https://leetcode.com/problems/container-with-most-water/discuss/1069818/C%2B%2B-or-Two-Pointers-Greedy-or-O(n)-0ms-Beats-100-or-Explanation
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int maxarea=0;
        int l=0,r=n-1;
        while(l<r)
        {
            int lh=height[l];
            int rh=height[r];
            maxarea=max(maxarea,(r-l)*min(lh,rh));
            if(lh<rh)
                  l++;
            else
                  r--;
        }
        return maxarea;
    }
};
