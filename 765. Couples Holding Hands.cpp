//Editorial: https://leetcode.com/problems/couples-holding-hands/discuss/253545/C%2B%2B-Union-Find-beats-100
class Solution {
public:
    int n;
    vector<int> parent;
    void setparent(int x,int y)
    {
        parent[x]=y;
    }
    int find(int x)
    {
        if(x!=parent[x])
            parent[x]=find(parent[x]);
        return parent[x];
    }
    bool findpar(int x,int y)
    {
        int px=find(x);
        int py=find(y);
        if(px==py)
            return false;
        parent[px]=py;
        return true;
    }
    int minSwapsCouples(vector<int>& row) {
        n=row.size();
        parent.resize(n);
        int ans=0;
        for(int i=0;i<n;i+=2)
        {
            setparent(row[i],row[i]);
            setparent(row[i+1],row[i]);
        }
        for(int i=0;i<n;i+=2)
        {
            if(findpar(i,i+1))
                ans+=1;
        }
        return ans;
    }
};
