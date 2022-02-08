//Editorial: https://youtu.be/1ZGJzvkcLsA, https://leetcode.com/problems/spiral-matrix/discuss/978853/C%2B%2B-or-0ms-faster-than-100-or-Easy-solution-with-proper-explanation
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n=matrix.size();
        int m=matrix[0].size();
        int top=0,bottom=n-1,right=m-1,left=0;
        int dir=1;
        while(top<=bottom and left<=right)
        {
           if(dir==1)
           {
               for(int i=left;i<=right;i++)
                   ans.push_back(matrix[top][i]);
               top++;
               dir=2;
           }
            else if(dir==2)
            {
                for(int i=top;i<=bottom;i++)
                    ans.push_back(matrix[i][right]);
                right--;
                dir=3;
            }
            else if(dir==3)
            {
                for(int i=right;i>=left;i--)
                {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
                dir=4;
            }
            else
            {
                for(int i=bottom;i>=top;i--)
                    ans.push_back(matrix[i][left]);
                left++;
                dir=1;
            }
        }
        return ans;
    }
};
