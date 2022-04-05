//Editorial: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/discuss/510249/JavaPython-3-2-similar-O(m-+-n)-codes-w-brief-explanation-and-analysis./453860
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++)
        {
            int low=0,high=n-1;
            while(low<=high)
            {
                int mid=low+(high-low)/2;
                if(grid[i][mid]<0)
                {
                    high=mid-1;
                }
                else 
                    low=mid+1;
            }
            ans+=(n-low);
        }
        return ans;
    }
};
