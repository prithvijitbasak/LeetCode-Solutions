//Editorial: https://leetcode.com/problems/surface-area-of-3d-shapes/discuss/473235/892.-Surface-Area-of-3D-Shapes.-C++-solution-with-visual-presentation
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                    continue;
                ans+=(grid[i][j]*6)-2*(grid[i][j]-1);
                if(i<n-1)
                    ans-=2*min(grid[i][j],grid[i+1][j]);
                if(j<n-1)
                    ans-=2*min(grid[i][j],grid[i][j+1]);
            }
        }
        return ans;
    }
};
