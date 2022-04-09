//Editorial: https://leetcode.com/problems/flipping-an-image/solution/
class Solution {
public:
    //here tc is O(n) where n is the all the elements in the matrix
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int m=image.size();
        int n=image[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<(n+1)/2;j++)
            {
                int temp=image[i][j]^1;
                image[i][j]=image[i][n-1-j]^1;
                image[i][n-1-j]=temp;
            }
        }
        return image;
    }
};
