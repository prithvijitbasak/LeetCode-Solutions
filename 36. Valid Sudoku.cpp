//Editorial: https://leetcode.com/problems/valid-sudoku/discuss/1332984/C%2B%2B-Simple-and-Easy-10-Short-Line-Solution
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<int>> row(9),col(9),block(9);
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                    continue;
                int curr=board[i][j]-'0';
                if(row[i].count(curr) or col[j].count(curr) or block[3*(i/3)+(j/3)].count(curr))
                    return false;
                row[i].insert(curr);
                col[j].insert(curr);
                block[3*(i/3)+(j/3)].insert(curr);
            }
        }
        return true;
    }
};
