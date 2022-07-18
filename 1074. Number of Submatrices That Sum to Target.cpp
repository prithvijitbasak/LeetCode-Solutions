//Editorial: https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/discuss/1162927/Optimization-from-Brute-Force-to-Optimized-Solution-w-Easy-Explanation
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=1;j<n;j++)
                matrix[i][j]+=matrix[i][j-1];
        }
        unordered_map<int,int> ump;
        int ans=0;
        for(int colstart=0;colstart<n;colstart++)
        {
            for(int colend=colstart;colend<n;colend++)
            {
                ump={{0,1}};
                int sum=0;
                for(int row=0;row<m;row++)
                {
                    sum+=matrix[row][colend]-(colstart?matrix[row][colstart-1]:0);
                    ans+=ump[sum-target];
                    ump[sum]+=1;
                }
            }
        }
        return ans;
    }
};
