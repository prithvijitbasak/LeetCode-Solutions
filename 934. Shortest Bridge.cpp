//Editorial: https://leetcode.com/problems/shortest-bridge/discuss/189440/Python-concise-DFS-and-BFS-in-1-solution
class Solution {
public:
    vector<vector<int>> vis;
    int n;
    vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
    queue<pair<int,int>> q;
    void dfs(vector<vector<int>> &grid,int x,int y)
    {
        vis[x][y]=1;
        q.push({x,y});
        for(int i=0;i<4;i++)
        {
            int dx=x+dir[i][0];
            int dy=y+dir[i][1];
            if(dx>=0 && dy>=0 && dx<n && dy<n)
            {
                if(!vis[dx][dy] && grid[dx][dy]==1)
                    dfs(grid,dx,dy);
            }
        }
    }
    int shortestBridge(vector<vector<int>> &grid) 
    {
        n=grid.size();
        vis.resize(n,vector<int>(n,0));
        int f=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    dfs(grid,i,j);
                    f=1;
                    break;
                }
            }
            if(f)
                break;
        }
        int ans=0;
        while(!q.empty())
        {
            int len=q.size();
            ans+=1;
            while(len--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                vis[x][y]=1;
                for(int i=0;i<4;i++){
                    int dx=x+dir[i][0];
                    int dy=y+dir[i][1];
                    if(dx>=0 && dy>=0 && dx<n && dy<n)
                    {
                       if(!vis[dx][dy] && grid[dx][dy]==1)
                           return ans-1;
                       else if(!vis[dx][dy] && grid[dx][dy]==0)
                       {
                           vis[dx][dy]=1;
                           q.push({dx,dy});
                       }
                    }
                }
            }
        }
        return -1;
    }
};  
