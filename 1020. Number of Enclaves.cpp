//Editorial: https://leetcode.com/problems/number-of-enclaves/discuss/266168/Easy-Java-DFS-6ms-solution
class Solution {
public:
    void dfs(vector<vector<int>> &grid,int row,int col,int m,int n)
    {
        if(row<0 or row>=m or col<0 or col>=n or !grid[row][col])
            return;
        grid[row][col]=0;
        dfs(grid,row+1,col,m,n);
        dfs(grid,row-1,col,m,n);
        dfs(grid,row,col+1,m,n);
        dfs(grid,row,col-1,m,n);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int ans=0;
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((i==0 or j==0 or i==m-1 or j==n-1) and grid[i][j]==1)
                    dfs(grid,i,j,m,n);
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j])
                    ans+=1;
            }
        }
        return ans;
    }
};
