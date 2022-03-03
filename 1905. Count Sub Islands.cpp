//Editorial: https://leetcode.com/problems/count-sub-islands/discuss/1284224/C%2B%2B-DFS
class Solution {
public:
    void dfs(vector<vector<int>> &grid1,vector<vector<int>> &grid2,int row,int col,int &cnt)
    {
        int m=grid1.size(),n=grid1[0].size();
        if(row<0 or row>=m or col<0 or col>=n)
            return;
        if(grid2[row][col]==1 and grid1[row][col]==0)
            cnt=0;
        if(grid2[row][col]==0)
            return;
        grid2[row][col]=0;
        dfs(grid1,grid2,row+1,col,cnt);
        dfs(grid1,grid2,row-1,col,cnt);
        dfs(grid1,grid2,row,col+1,cnt);
        dfs(grid1,grid2,row,col-1,cnt);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans=0;
        int m=grid2.size();
        int n=grid2[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid2[i][j]==1)
                {
                    int cnt=1;
                    dfs(grid1,grid2,i,j,cnt);
                    ans+=cnt;
                }
            }
        }
        return ans;
    }
};
