//Editorial: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/solutions/1686627/c-java-python-6-lines-sort-and-greedy-image-explanation/?orderBy=most_votes
class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b)
    {
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),comp);
        int n=points.size();
        int ans=0,arrow=0;
        for(int i=0;i<n;i++)
        {
            if(ans==0 or arrow<points[i][0])
            {
                ans+=1;
                arrow=points[i][1];
            }
        }
        return ans;
    }
};
