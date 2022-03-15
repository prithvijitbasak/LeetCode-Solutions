//Editorial: https://leetcode.com/problems/minimum-falling-path-sum/discuss/1191340/C%2B%2B-4-Solutions-from-bruteforce-to-dp-with-explainations
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int ans=INT_MAX;
        for(int i=1;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                int left,right,middle;
                if(j==0)
                {
                    right=matrix[i-1][j+1];
                    middle=matrix[i-1][j];
                    matrix[i][j]+=min(right,middle);
                }
                else if(j==cols-1)
                {
                    left=matrix[i-1][j-1];
                    middle=matrix[i-1][j];
                    matrix[i][j]+=min(left,middle);
                }
                else
                {
                    left=matrix[i-1][j-1];
                    middle=matrix[i-1][j];
                    right=matrix[i-1][j+1];
                    matrix[i][j]+=min(left,min(middle,right));
                }
            }
        }
        for(int j=0;j<cols;j++)
            ans=min(ans,matrix[rows-1][j]);
        return ans;
    }
};
