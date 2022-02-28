//Editorial: Just iterate over the whole array and keep track of the lowest one.
class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int ans=-1,mindist=INT_MAX;
        for(int i=0;i<points.size();i++)
        {
            if(points[i][0]==x or points[i][1]==y)
            {
                int dist=abs(x-points[i][0])+abs(points[i][1]-y);
                if(dist<mindist)
                {
                    ans=i;
                    mindist=dist;
                }
            }
        }
        return ans;
    }
};
