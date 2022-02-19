//Editorial: https://youtu.be/pUAPcVlHLKA
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m=grid.size(),n=grid[0].size();
        int cnt=0,tot=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]!=0)
                    tot+=1;
                if(grid[i][j]==2)
                    q.push({i,j});
            }
        }
        vector<int> dx={0,0,-1,1};
        vector<int> dy={1,-1,0,0};
        int time=0;
        while(!q.empty())
        {
            int k=q.size();
            cnt+=k;
            while(k--)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int xx=x+dx[i];
                    int yy=y+dy[i];
                    if(xx<0 or xx>=m or yy<0 or yy>=n or grid[xx][yy]!=1)
                        continue;
                    grid[xx][yy]=2;
                    q.push({xx,yy});
                }
            }
            if(!q.empty())
                time+=1;
        }
        if(cnt==tot)
            return time;
        else
            return -1;
    }
};
