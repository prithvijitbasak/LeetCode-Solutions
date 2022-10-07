//Editorial: Just traverse through the grid and add the positions of the grid.
class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int ans=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m-2;i++)
        {
            for(int j=0;j<n-2;j++)
            {
                int sum=0;
                sum+=grid[i][j]+grid[i][j+1]+grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2];
                ans=max(ans,sum);
            }
        }
        return ans;
    }
};
