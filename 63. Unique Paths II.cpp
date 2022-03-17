//Editorial: https://youtu.be/z6kelCB0ww4, https://leetcode.com/problems/unique-paths-ii/solution/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        if(grid[0][0]==1)
            return 0;
        grid[0][0]=1;
        for(int i=1;i<row;i++)
        {
            if(grid[i][0]==0 and grid[i-1][0]==1)
                grid[i][0]=1;
            else
                grid[i][0]=0;
        }
        for(int j=1;j<col;j++)
        {
            if(grid[0][j]==0 and grid[0][j-1]==1)
                grid[0][j]=1;
            else
                grid[0][j]=0;
        }
        for(int i=1;i<row;i++)
        {
            for(int j=1;j<col;j++)
            {
                if(grid[i][j]==0)
                    grid[i][j]=grid[i-1][j]+grid[i][j-1];
                else
                    grid[i][j]=0;
            }
        }
        return grid[row-1][col-1];
    }
};
