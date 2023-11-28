//Editorial: https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/solutions/4329355/easy-video-solution-visualization-square-of-min-max-continuous-in-two-arrays/
class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& h, vector<int>& v) {
        // tutorial : https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/solutions/4329355/easy-video-solution-visualization-square-of-min-max-continuous-in-two-arrays/
        // here we are will just remove the consecutive bars 
        // as removing the consecutive bars will give me a sqare rather
        // than removing non-consecutive bars
        // after removing from horizontal and vertical bars we will 
        // check the minimum among them to get the side of the square.
        sort(h.begin(), h.end());
        sort(v.begin(), v.end());
        int temp = 1;
        int maxh = 1, maxv = 1;
        for(int i=1;i<h.size();i++)
        {
            if(h[i] - h[i-1] == 1)
                temp += 1;
            else
                temp = 1;
            maxh = max(maxh, temp);
        }
        temp = 1;
        for(int i=1;i<v.size();i++)
        {
            if(v[i] - v[i-1] == 1)
                temp += 1;
            else
                temp = 1;
            maxv = max(maxv, temp);
        }
        int ans = min(maxv+1, maxh+1);
        return ans * ans;
    }
};
