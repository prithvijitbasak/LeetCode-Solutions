//Editorial: https://leetcode.com/problems/queue-reconstruction-by-height/discuss/427157/Three-different-C++-solutions.-from-O(n2)-to-O(nlogn).-faster-than-99.
class Solution {
public:
    static bool comp(vector<int> &p1,vector<int> &p2)
    {
        if(p1[0]!=p2[0])
            return p1[0]>p2[0];
        else
            return p1[1]<p2[1];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ans;
        sort(people.begin(),people.end(),comp);
        int n=people.size();
        for(int i=0;i<n;i++)
            ans.insert(ans.begin()+people[i][1],people[i]);
        return ans;
    }
};
