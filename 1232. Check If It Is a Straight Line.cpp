//Editorial: https://leetcode.com/problems/check-if-it-is-a-straight-line/discuss/408984/JavaPython-3-check-slopes-short-code-w-explanation-and-analysis.
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        //formula for collinearity
        //(y - y1) / (x - x1) = (y1 - y0) / (x1 - x0)
        int x1=coordinates[1][0],y1=coordinates[1][1];
        int x0=coordinates[0][0],y0=coordinates[0][1];
        int dx=x1-x0;
        int dy=y1-y0;
        for(auto it:coordinates)
        {
            int x=it[0];
            int y=it[1];
            if(dx*(y-y1)!=dy*(x-x1))
                return false;
        }
        return true;
    }
};
