//Editorial: https://leetcode.com/problems/sort-the-matrix-diagonally/discuss/489775/C++-elegant-map-solution-easy-to-understand/829283
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        map<int,priority_queue<int,vector<int>,greater<int>>> mp;
        int m=mat.size(),n=mat[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                mp[i-j].push(mat[i][j]);
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                mat[i][j]=mp[i-j].top();
                mp[i-j].pop();
            }
        }
        return mat;
    }
};
