//Editorial: https://leetcode.com/problems/pacific-atlantic-water-flow/discuss/1126938/Short-and-Easy-w-Explanation-and-diagrams-or-Simple-Graph-traversals-DFS-and-BFS
class Solution {
public:
    int m, n;
    vector<vector<int>> atlantic, pacific;
	vector<vector<int>> ans;    
    void dfs(vector<vector<int>> &heights,vector<vector<int>> &vis,int i,int j)
    {        
        if(vis[i][j]) 
            return;
        vis[i][j] = 1;
        if(atlantic[i][j] && pacific[i][j]) 
            ans.push_back(vector<int>{i, j});    
        if(i + 1 <  m and heights[i + 1][j] >= heights[i][j]) 
            dfs(heights, vis, i + 1, j); 
        if(i - 1 >= 0 and heights[i - 1][j] >= heights[i][j]) 
            dfs(heights, vis, i - 1, j);
        if(j + 1 <  n and heights[i][j + 1] >= heights[i][j]) 
            dfs(heights, vis, i, j + 1); 
        if(j - 1 >= 0 and heights[i][j - 1] >= heights[i][j]) 
            dfs(heights, vis, i, j - 1);
    }
    vector<vector<int> > pacificAtlantic(vector<vector<int>>& heights) 
    {
        m=heights.size();
        n=heights[0].size();
        atlantic = pacific = vector<vector<int> >(m, vector<int>(n, false));
        for(int i = 0; i < m; i++) 
        {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, n - 1);   
        }
        for(int i = 0; i < n; i++)
        {
            dfs(heights, pacific, 0, i);
            dfs(heights, atlantic, m - 1, i);
        }
        return ans;
    }
};
