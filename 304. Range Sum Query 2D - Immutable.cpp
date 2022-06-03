//Editorial: https://leetcode.com/problems/range-sum-query-2d-immutable/solution/
class NumMatrix {
public:
    vector<vector<int>> dp;
    NumMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        dp.resize(m+1,vector<int> (n+1,0));
        if(m==0 or n==0)
            return;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                dp[i+1][j+1]=dp[i+1][j]+dp[i][j+1]+matrix[i][j]-dp[i][j];
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2+1][col2+1]-dp[row1][col2+1]-dp[row2+1][col1]+dp[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
