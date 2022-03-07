//Editorial: https://leetcode.com/problems/shortest-path-in-binary-matrix/discuss/312814/simple-BFS-C%2B%2B
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int row=grid.size(),col=grid[0].size();
        queue<pair<int,int>> q;
        if(grid[0][0]!=0 or grid[row-1][col-1]!=0)
            return -1;
        vector<vector<int>> dir={{0,1},{1,0},{-1,0},{0,-1},{1,-1},{-1,1},{1,1},{-1,-1}};
        grid[0][0]=1;
        q.push({0,0});
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            if(x==row-1 and y==col-1)
                return grid[x][y];
            for(int i=0;i<8;i++)
            {
                int dx=x+dir[i][0];
                int dy=y+dir[i][1];
                if(dx>=0 and dx<row and dy>=0 and dy<col and grid[dx][dy]==0)
                {
                    q.push({dx,dy});
                    grid[dx][dy]=grid[x][y]+1;
                }
            }
        }
        return -1;
    }
};
