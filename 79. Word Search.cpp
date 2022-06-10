//Editorial: https://leetcode.com/problems/word-search/discuss/27658/Accepted-very-short-Java-solution.-No-additional-space.
class Solution {
public:
    vector<vector<int>> dir={{0,-1},{1,0},{0,1},{-1,0}};
    bool dfs(vector<vector<char>> &board,string word,int x,int y,int idx)
    {
        if(idx==word.size())
            return true;
        if(x<0 or y<0 or x>=board.size() or y>=board[0].size() or board[x][y]=='*')
            return false;
        if(board[x][y]!=word[idx])
            return false;
        char ch=board[x][y];
        board[x][y]='*';
        for(int i=0;i<4;i++)
        {
            if(dfs(board,word,x+dir[i][0],y+dir[i][1],idx+1))
                return true;
        }
        board[x][y]=ch;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dfs(board,word,i,j,0))
                    return true;
            }
        }
        return false;
    }
};
