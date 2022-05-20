//Editorial: https://leetcode.com/problems/unique-paths-iii/discuss/1553805/C++-Simple-and-Clean-DFS-Solution-Explained-0ms-Faster-than-100
class Solution {
public:
    int ans=0,sx,sy,empty=1,row,col;
    void dfs(vector<vector<int>> &grid,int x,int y)
    {
        if(x<0 or x>=row or y<0 or y>=col or grid[x][y]<0)
            return;
        if(grid[x][y]==2)
        {
            if(empty==0)
                ans+=1;
            return;
        }
        grid[x][y]=-2;
        empty--;
        dfs(grid,x+1,y);
        dfs(grid,x-1,y);
        dfs(grid,x,y+1);
        dfs(grid,x,y-1);
        grid[x][y]=0;
        empty++;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        row=grid.size();
        col=grid[0].size();
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==0)
                    empty+=1;
                else if(grid[i][j]==1)
                {
                    sx=i;
                    sy=j;
                }
            }
        }
        dfs(grid,sx,sy);
        return ans;
    }
};
