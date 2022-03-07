//Editorial: https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/discuss/1329078/C%2B%2B-BFS-solution-oror-commented
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        int m=maze.size(),n=maze[0].size();
        queue<pair<int,int>> q;
        q.push({e[0],e[1]});
        maze[e[0]][e[1]]='+';
        int moves=1;
        vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty())
        {
            int len=q.size();
            while(len--)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int dx=x+dir[i][0];
                    int dy=y+dir[i][1];
                    if(dx>=0 and dy>=0 and dx<m and dy<n and maze[dx][dy]=='.')
                    {
                        if(dx==0 or dy==0 or dx==m-1 or dy==n-1)
                            return moves;
                        else
                        {
                            q.push({dx,dy});
                            maze[dx][dy]='+';
                        }
                    }
                }
            }
            moves+=1;
        }
        return -1;
    }
};
