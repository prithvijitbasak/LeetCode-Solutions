//Editorial: Same as N Queens 1(N Queens 1 editorial: https://youtu.be/i05Ju7AftcM)
class Solution {
public:
     void solve(int col,int &cnt,vector<int> &leftrow,vector<int> &upperdiagonal, vector<int> &lowerdiagonal,int n)
    {
        if(col==n)
        {
            cnt++;
            return;
        }
        for(int row=0;row<n;row++)
        {
            if(leftrow[row]==0 and upperdiagonal[n-1+col-row]==0 and lowerdiagonal[row+col]==0)
            {
                upperdiagonal[n-1+col-row]=1;
                lowerdiagonal[row+col]=1;
                leftrow[row]=1;
                solve(col+1,cnt,leftrow,upperdiagonal,lowerdiagonal,n);
                upperdiagonal[n-1+col-row]=0;
                lowerdiagonal[row+col]=0;
                leftrow[row]=0;
            }
        }
    }
    int totalNQueens(int n) {
        vector<int> leftrow(n,0),upperdiagonal(2*n-1,0),lowerdiagonal(2*n-1,0);
        int cnt=0;
        solve(0,cnt,leftrow,upperdiagonal,lowerdiagonal,n);
        return cnt;
    }
};
