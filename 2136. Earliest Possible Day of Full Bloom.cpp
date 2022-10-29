//Editorial: https://youtu.be/R6Mc2W6rOZw
class Solution {
public:
    static bool comp(pair<int,int> &p1,pair<int,int> &p2)
    {
        return p1.second>p2.second;
    }
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int ans=0;
        vector<pair<int,int>> arr;
        int n=growTime.size();
        for(int i=0;i<n;i++)
            arr.push_back({plantTime[i],growTime[i]});
        sort(arr.begin(),arr.end(),comp);
        int prevtime=0;
        for(int i=0;i<n;i++)
        {
            prevtime+=arr[i].first;
            ans=max(ans,prevtime+arr[i].second);
        }
        return ans;
    }
};
