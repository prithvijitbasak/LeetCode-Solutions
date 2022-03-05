// Editorial: Just go through each row and column and add both the diagonal elements. In the end check if the size of the matrix is odd
// then take out the center element of the matrix as it will get added twice and then return the value.
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int ans=0;
        int n=mat.size();
        for(int i=0;i<n;i++)
            ans+=mat[i][i]+mat[i][n-i-1];
        if(n&1)
            ans-=mat[n/2][n/2];
        return ans;
    }
};
