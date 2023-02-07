//Editorail: https://leetcode.com/problems/disconnect-path-in-a-binary-matrix-by-at-most-one-flip/solutions/3141656/explained-run-dfs-2-times-very-simple-and-easy-to-understand-solution/
class Solution {
public:
    bool dfs(vector<vector<int>> &grid,int x,int y)
    {
        if(x+1==grid.size() and y+1==grid[0].size())
            return true;
        if(x>=grid.size() or y>=grid[0].size() or grid[x][y]==0)
            return false;
        grid[x][y]=0;
        return dfs(grid,x+1,y) or dfs(grid,x,y+1);
    }
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        if(dfs(grid,0,0)==false)
            return true;
        grid[0][0]=1;
        return dfs(grid,0,0)==false;
    }
};
