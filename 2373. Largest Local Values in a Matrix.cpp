//Editorial: Just loop through the matrix and find the largest for each 3x3 matrix.
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> ans(n-2,vector<int> (n-2));
        for(int k=0;k<n-2;k++)
        {
            for(int l=0;l<n-2;l++)
            {
                int maxi=0;
                for(int i=k;i<k+3;i++)
                {
                    for(int j=l;j<l+3;j++)
                    {
                        if(grid[i][j]>maxi)
                            maxi=grid[i][j];
                    }
                }
                ans[k][l]=maxi;
            }
        }
        return ans;
    }
};
