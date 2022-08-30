//Editorial: Try to solve Rotate Image problem before solving this. Editorial for Rotate Image is : https://leetcode.com/problems/rotate-image/discuss/18872/A-common-method-to-rotate-the-image
class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat==target)
            return true;
        int deg=3;
        while(deg--)
        {
            reverse(mat.begin(),mat.end());
            for(int i=0;i<mat.size();i++)
            {
                for(int j=i+1;j<mat[i].size();j++)
                    swap(mat[i][j],mat[j][i]);
            }
            if(mat==target)
                return true;
        }
        return false;
    }
};
