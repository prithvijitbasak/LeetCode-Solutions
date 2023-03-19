//Editorial: https://leetcode.com/problems/check-knight-tour-configuration/solutions/3314113/bruteforce-very-simple-easy-to-understand-solution/?orderBy=most_votes
class Solution {
public:
    vector<vector<int>> dir={{-1,2},{-1,-2},{-2,-1},{-2,1},{1,2},{1,-2},{2,-1},{2,1}};
    bool checkValidGrid(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0,maxcnt=m*n-1;
        if(grid[0][0]!=0)
            return false;
        int x=0,y=0;
        while(cnt<maxcnt)
        {
            cnt+=1;
            int i,j;
            int f=0;
            for(auto it:dir)
            {
                i=x+it[0];
                j=y+it[1];
                if(i>=0 and i<m and j>=0 and j<n and grid[i][j]==cnt)
                {
                    x=i;
                    y=j;
                    f=1;
                    break;
                }
            }
            if(!f)
                return false;
        }
        return true;
    }
};
