//Editorial: https://leetcode.com/problems/number-of-provinces/discuss/873741/Simple-C%2B%2B-Solution-oror-Fully-Explained-at-begineers-level-oror-Easy-Understanding-of-UNION-concept
class Solution {
public:
    vector<int> parent;
    int findparent(int n)
    {
        if(parent[n]==-1)
            return n;
        return parent[n]=findparent(parent[n]);
    }
    void _union(int x,int y)
    {
        int px=findparent(x);
        int py=findparent(y);
        if(px==py)
            return;
        parent[px]=py;
    }
    int findCircleNum(vector<vector<int>>& grid) {
        int n=grid.size();
        parent=vector<int> (n,-1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j])
                    _union(i,j);
            }
        }
        int ans=0;
        for(auto it:parent)
        {
            if(it==-1)
                ans+=1;
        }
        return ans;
    }
};
