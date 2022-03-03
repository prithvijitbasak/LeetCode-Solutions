//Editorial: https://youtu.be/QcY61aBwibI
class Solution {
public:
    bool dfs(vector<vector<int>> &grid,int row,int col,int m,int n)
    {
        if(row<0 or row>=m or col<0 or col>=n)
            return false;
        if(grid[row][col])
            return true;
        grid[row][col]=1;
        bool up=dfs(grid,row+1,col,m,n);
        bool down=dfs(grid,row-1,col,m,n);
        bool right=dfs(grid,row,col+1,m,n);
        bool left=dfs(grid,row,col-1,m,n);
        return up and down and right and left;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int ans=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0 and dfs(grid,i,j,m,n))
                    ans+=1;
            }
        }
        return ans;
    }
};
