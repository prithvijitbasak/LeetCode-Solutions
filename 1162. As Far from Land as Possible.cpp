//Editorial: https://leetcode.com/problems/as-far-from-land-as-possible/discuss/422691/7ms-DP-solution-with-example-beats-100
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                    continue;
                grid[i][j]=201;
                if(i>0)
                    grid[i][j]=min(grid[i][j],grid[i-1][j]+1);
                if(j>0)
                    grid[i][j]=min(grid[i][j],grid[i][j-1]+1);
            }
        }
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(grid[i][j]==1)
                    continue;
                if(i<m-1)
                    grid[i][j]=min(grid[i][j],grid[i+1][j]+1);
                if(j<n-1)
                    grid[i][j]=min(grid[i][j],grid[i][j+1]+1);
                ans=max(ans,grid[i][j]);
            }
        }
        return ans==201?-1:ans-1;
    }
};
