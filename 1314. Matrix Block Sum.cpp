//Editorial: https://leetcode.com/problems/matrix-block-sum/discuss/549010/C%2B%2B-oror-64.38-time-oror-100.00-space-oror-graph-illustration
class Solution {
public:
    vector<vector<int>> sum(vector<vector<int>> &mat)
    {
        vector<vector<int>> prefixsum=mat;
        for(int i=0;i<mat.size();i++)
        {
            int res=0;
            for(int j=0;j<mat[0].size();j++)
            {
                res+=mat[i][j];
                if(i>0)
                    prefixsum[i][j]=prefixsum[i-1][j]+res;
                else
                    prefixsum[i][j]=res;
            }
        }
        return prefixsum;
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        vector<vector<int>> prefixsum=sum(mat);
        vector<vector<int>> ans=prefixsum;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                int upperi=((i+k)>=mat.size())?mat.size()-1:(i+k);
                int upperj=((j+k)>=mat[0].size())?mat[0].size()-1:(j+k);
                int loweri=((i-k)<=0)?0:(i-k);
                int lowerj=((j-k)<=0)?0:(j-k);
                ans[i][j]=prefixsum[upperi][upperj]-((loweri==0)?0:prefixsum[loweri-1][upperj])-((lowerj==0)?0:prefixsum[upperi][lowerj-1])+((loweri==0 or lowerj==0)?0:prefixsum[loweri-1][lowerj-1]);
            }
        }
        return ans;
    }
};
