//Editorial: https://leetcode.com/problems/find-a-peak-element-ii/discuss/1276556/JavaPythonC++-Clear-Explanation-with-Images-or-M*Log(N)-or-Very-Short-code
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int startcol=0,endcol=mat[0].size()-1;
        while(startcol<=endcol)
        {
            int midcol=startcol+(endcol-startcol)/2;
            int maxrow=0;
            for(int i=0;i<mat.size();i++)
            {
                if(mat[i][midcol]>=mat[maxrow][midcol])
                    maxrow=i;
            }
            int lib=midcol-1>=startcol and mat[maxrow][midcol-1]>mat[maxrow][midcol];
            int rib=midcol+1<=endcol and mat[maxrow][midcol+1]>mat[maxrow][midcol];
            if(!lib and !rib)
                return vector<int> {maxrow,midcol};
            else if(rib)
                startcol=midcol+1;
            else
                endcol=midcol-1;
        }
        return vector<int> {-1,-1};
    }
};
