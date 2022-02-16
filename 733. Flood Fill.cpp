//Editorial: https://youtu.be/RwozX--B_Xs
class Solution {
public:
    void dfs(vector<vector<int>> &image,int sr,int sc,int newColor,int row,int col,int source)
    {
        if(sr<0 or sr>=row or sc<0 or sc>=col)
            return;
        else if(image[sr][sc]!=source)
            return;
        image[sr][sc]=newColor;
        dfs(image,sr+1,sc,newColor,row,col,source);
        dfs(image,sr,sc+1,newColor,row,col,source);
        dfs(image,sr-1,sc,newColor,row,col,source);
        dfs(image,sr,sc-1,newColor,row,col,source);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int row=image.size(),col=image[0].size();
        int source=image[sr][sc];
        if(image[sr][sc]==newColor)
            return image;
        dfs(image,sr,sc,newColor,row,col,source);
        return image;
    }
};
