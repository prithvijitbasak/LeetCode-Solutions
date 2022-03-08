//Approach 1: Using dsu 
//Editorial: https://leetcode.com/problems/number-of-operations-to-make-network-connected/discuss/618686/C%2B%2B-or-Union-Find-or-Connected-components
class Solution {
public:
    vector<int> parent;
    int findparent(int i)
    {
        if(parent[i]==i)
            return i;
        return parent[i]=findparent(parent[i]);
    }
    int makeConnected(int n, vector<vector<int>>& grid) {
        int c=grid.size();
        if(c<n-1)
            return -1;
        parent.resize(n);
        for(int i=0;i<n;i++)
            parent[i]=i;
        for(int i=0;i<c;i++)
        {
            int x=findparent(grid[i][0]);
            int y=findparent(grid[i][1]);
            if(x!=y)
                parent[y]=x;
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(parent[i]==i)
                ans+=1;
        }
        return ans-1;
    }
};
