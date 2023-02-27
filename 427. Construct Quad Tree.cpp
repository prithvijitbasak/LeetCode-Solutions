//Editorial: https://leetcode.com/problems/construct-quad-tree/editorial/
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    bool same(vector<vector<int>> &grid,int x,int y,int len)
    {
        for(int i=x;i<x+len;i++)
        {
            for(int j=y;j<y+len;j++)
            {
                if(grid[x][y]!=grid[i][j])
                    return false;
            }
        }
        return true;
    }
    Node* solve(vector<vector<int>> &grid,int x,int y,int len)
    {
        if(same(grid,x,y,len))
            return new Node(grid[x][y],true);
        else
        {
            Node* root=new Node(false,false);
            len/=2;
            root->topLeft=solve(grid,x,y,len);
            root->topRight=solve(grid,x,y+len,len);
            root->bottomLeft=solve(grid,x+len,y,len);
            root->bottomRight=solve(grid,x+len,y+len,len);
            return root;
        }
    }
    Node* construct(vector<vector<int>>& grid) {
        int n=grid.size();
        return solve(grid,0,0,n);
    }
};
