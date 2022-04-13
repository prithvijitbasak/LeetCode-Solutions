//Editorial: Just simulate the process. Go through the solution to get more clarity.
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int> (n));
        int top=0,bottom=n-1,left=0,right=n-1;
        int dir=1,j=1;
        while(top<=bottom and left<=right)
        {
            if(dir==1)
            {
                for(int i=left;i<=right;i++)
                {
                    ans[top][i]=j;
                    j++;
                }
                top++;
                dir=2;
            }
            else if(dir==2)
            {
                for(int i=top;i<=bottom;i++)
                {
                    ans[i][right]=j;
                    j++;
                }
                right--;
                dir=3;
            }
            else if(dir==3)
            {
                for(int i=right;i>=left;i--)
                {
                    ans[bottom][i]=j;
                    j++;
                }
                bottom--;
                dir=4;
            }
            else
            {
                for(int i=bottom;i>=top;i--)
                {
                    ans[i][left]=j;
                    j++;
                }
                left++;
                dir=1;
            }
        }
        return ans;
    }
};
