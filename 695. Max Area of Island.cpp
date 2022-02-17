//Editorial: https://leetcode.com/problems/max-area-of-island/discuss/108533/JavaC++-Straightforward-dfs-solution/110694
class Solution {
public:
    int dfs(vector<vector<int>> &grid,int i,int j)
    {
        if(i<0 or i>=grid.size() or j<0 or j>=grid[0].size() or grid[i][j]!=1)
            return 0;
        grid[i][j]=-1;
        int cnt=1;
        cnt+=dfs(grid,i+1,j);
        cnt+=dfs(grid,i-1,j);
        cnt+=dfs(grid,i,j+1);
        cnt+=dfs(grid,i,j-1);
        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==1)
                    ans=max(ans,dfs(grid,i,j));
            }
        }
        return ans;
    }
};
