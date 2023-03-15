//Editorial: https://leetcode.com/problems/k-closest-points-to-origin/solutions/1647773/c-python-simple-solutions-w-explanation-sort-heap-randomized-quickselect-o-n/?orderBy=most_votes
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>> maxh;
        for(auto it:points)
        {
            maxh.push({it[0]*it[0]+it[1]*it[1],{it[0],it[1]}});
            if(maxh.size()>k)
                maxh.pop();
        }
        vector<vector<int>> ans;
        while(!maxh.empty())
        {
            ans.push_back({maxh.top().second.first,maxh.top().second.second});
            maxh.pop();
        }
        return ans;
    }
};
