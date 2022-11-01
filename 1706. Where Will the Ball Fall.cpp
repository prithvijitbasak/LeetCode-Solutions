//Editorial: https://leetcode.com/problems/where-will-the-ball-fall/discuss/988244/C-++-Easy-Solution-oror-DFS
class Solution {
public:
    bool isvalid(vector<vector<int>> &grid,int r,int c)
    {
        if(r>=grid.size() or c>=grid[0].size() or r<0 or c<0)
            return false;
        return true;
    }
    int dfs(vector<vector<int>> &grid,int r,int c)
    {
        if(r==grid.size())
            return c;
        if(isvalid(grid,r,c))
        {
            if(grid[r][c]==1)
            {
                if(isvalid(grid,r,c+1) and grid[r][c+1]==1)
                    return dfs(grid,r+1,c+1);
            }
            else
            {
                if(isvalid(grid,r,c-1) and grid[r][c-1]==-1)
                    return dfs(grid,r+1,c-1);
            }
        }
        return -1;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int rows=grid.size(),cols=grid[0].size();
        vector<int> ans(cols,0);
        for(int c=0;c<cols;c++)
            ans[c]=dfs(grid,0,c);
        return ans;
    }
};
