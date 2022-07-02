//Editorial: https://leetcode.com/problems/minimum-area-rectangle/discuss/900264/IntuitiveWith-PicturesC++JavaExplanation
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int ans=INT_MAX;
        unordered_map<int,unordered_set<int>> ump;
        for(auto it:points)
            ump[it[0]].insert(it[1]);
        for(int i=0;i<points.size();i++)
        {
            for(int j=i+1;j<points.size();j++)
            {
                int x1=points[i][0],y1=points[i][1];
                int x2=points[j][0],y2=points[j][1];
                if(x1!=x2 and y1!=y2)
                {
                    if(ump[x1].find(y2)!=ump[x1].end() and ump[x2].find(y1)!=ump[x2].end())
                    {
                        ans=min(ans,abs(x1-x2)*abs(y1-y2));
                    }
                }
            }
        }
        return ans!=INT_MAX?ans:0;
    }
};
