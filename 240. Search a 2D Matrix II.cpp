//Editorial: https://leetcode.com/problems/search-a-2d-matrix-ii/discuss/66140/My-concise-O(m+n)-Java-solution
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=0,col=matrix[0].size()-1;
        while(row<=matrix.size()-1 and col>=0)
        {
            if(matrix[row][col]==target)
                return true;
            else if(target<matrix[row][col])
                col--;
            else
                row++;
        }
        return false;
    }
};
