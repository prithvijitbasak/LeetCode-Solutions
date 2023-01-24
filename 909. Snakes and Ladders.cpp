//Editorial: https://leetcode.com/problems/snakes-and-ladders/solutions/3092265/c-simple-bfs-with-full-explanation-beats-100/?orderBy=most_votes
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        queue<int> q;
        int n=board.size();
        vector<int> columns(n);
        iota(columns.begin(),columns.end(),0);
        int idx=1;
        vector<pair<int,int>> cells(n*n+1);
        for(int rows=n-1;rows>=0;rows--)
        {
            for(auto it:columns)
                cells[idx++]={rows,it};
            reverse(columns.begin(),columns.end());
        }
        vector<int> dist(n*n+1,-1);
        q.push(1);
        dist[1]=0;
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            for(int i=curr+1;i<=min(n*n,curr+6);i++)
            {
                int r=cells[i].first;
                int c=cells[i].second;
                int dest;
                if(board[r][c]!=-1)
                    dest=board[r][c];
                else
                    dest=i;
                if(dist[dest]==-1)
                {
                    dist[dest]=dist[curr]+1;
                    q.push(dest);
                }
            }
        }
        return dist[n*n];
    }
};
