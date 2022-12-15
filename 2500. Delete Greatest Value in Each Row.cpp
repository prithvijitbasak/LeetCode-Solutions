//Editorial: Just sort the rows and add the maximum values of each column to the answer.
class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++)
            sort(grid[i].begin(),grid[i].end());
        int ans=0;
        for(int j=n-1;j>=0;j--)
        {
            int i=0;
            int maxi=0;
            while(i<m)
            {
                maxi=max(maxi,grid[i][j]);
                i+=1;
            }
            ans+=maxi;
        }
        return ans;
    }
};
