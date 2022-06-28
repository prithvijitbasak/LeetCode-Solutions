//Editorial: Just iterate through the grid to check if the conditions are getting satisfied or not.
class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j and grid[i][j]==0)
                    return false;
                if(i==m-1-j and grid[i][j]==0)
                    return false;
                if(i!=j and i!=m-1-j and grid[i][j]!=0)
                    return false;
            }
        }
        return true;
    }
};
