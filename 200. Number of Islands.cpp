//Editorial: https://youtu.be/__98uL6wst8
class Solution {
public:
    void dfs(vector<vector<char>> &grid,int dx[],int dy[],int row,int col,int x,int y)
    {
        if(x<0 or x>=row or y<0 or y>=col or grid[x][y]!='1' )
            return;
        grid[x][y]='2';
        for(int i=0;i<4;i++)
            dfs(grid,dx,dy,row,col,x+dx[i],y+dy[i]);
    }
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int ans=0;
        if(row==0)
            return 0;
        int dx[]={-1,+1,0,0};
        int dy[]={0,0,-1,+1};
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]=='1')
                {
                    dfs(grid,dx,dy,row,col,i,j);
                    ans+=1;
                }
            }
        }
        return ans;
    }
};
