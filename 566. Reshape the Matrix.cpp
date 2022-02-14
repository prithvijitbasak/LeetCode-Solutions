//Editorial: https://leetcode.com/problems/reshape-the-matrix/discuss/1317151/C%2B%2B-One-Loop-Easy-Solution-or-Column-first-and-Row-first-Approaches
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m=mat.size(),n=mat[0].size();
        if(r*c!=m*n)
            return mat;
        vector<vector<int>> ans(r,vector<int> (c));
        for(int i=0;i<m*n;i++)
        {
            ans[i/c][i%c]=mat[i/n][i%n];
        }
        return ans;
    }
};
