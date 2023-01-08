//Editorial: https://leetcode.com/problems/max-points-on-a-line/solutions/2910679/max-points-on-a-line/?orderBy=most_votes
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans=0;
        int n=points.size();
        for(int i=0;i<n;i++)
        {
            unordered_map<double,int> ump;
            for(int j=0;j<n;j++)
            {
                if(j!=i)
                    ump[atan2(points[j][1]-points[i][1],points[j][0]-points[i][0])]+=1;
            }
            for(auto it:ump)
                ans=max(ans,it.second);
        }
        return ans+1;
    }
};
