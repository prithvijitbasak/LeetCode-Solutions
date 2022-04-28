//Editorial: https://leetcode.com/problems/path-with-minimum-effort/discuss/909200/C++-Concise-Dijikstra-algorithm-350ms
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row=heights.size();
        int col=heights[0].size();
        vector<vector<int>> dist(row,vector<int> (col,INT_MAX));
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dx={0,0,1,-1};
        vector<int> dy={1,-1,0,0};
        pq.push({0,0}); //dist and row*100+col
        while(!pq.empty())
        {
            int dista=pq.top().first;
            int x=pq.top().second/100;
            int y=pq.top().second%100;
            pq.pop();
            if(x==row-1 and y==col-1)
                return dista;
            if(dista>=dist[x][y])
                continue;
            dist[x][y]=dista;
            for(int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx<0 or nx>=row or ny<0 or ny>=col)
                    continue;
                int newdist=max(dista,abs(heights[x][y]-heights[nx][ny]));
                pq.push({newdist,nx*100+ny});
            }
        }
        return -1;
    }
};
