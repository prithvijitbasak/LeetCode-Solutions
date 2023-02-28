//Editorial: https://leetcode.com/problems/minimum-time-to-visit-a-cell-in-a-grid/solutions/3230800/c-java-python-ping-pong-dijkstra/?orderBy=most_votes
class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) 
    {
        if(grid[0][1]>1 and grid[1][0]>1) 
            return -1;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
        vector<vector<int>> vis(m,vector<int> (n, 0));
        priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;
        pq.push({grid[0][0],0,0});
        while(!pq.empty())
        {
            int time=pq.top()[0];
            int x=pq.top()[1];
            int y=pq.top()[2];
            pq.pop();
            if(x==m-1 and y==n-1)
                return time;
            if(vis[x][y])
                continue;
            vis[x][y]=1;
            for(auto it:dir)
            {
                int r=it[0]+x;
                int c=it[1]+y;
                if(r<0 or r>=m or c<0 or c>=n or vis[r][c])
                    continue;
                if(time+1>=grid[r][c])
                {
                    pq.push({time+1,r,c});
                    continue;
                }
                else
                {
                    int diff=grid[r][c]-time;
                    if(diff&1)
                        pq.push({grid[r][c],r,c});
                    else
                        pq.push({grid[r][c]+1,r,c});
                }
            }
        }
        return -1;
    }
};
