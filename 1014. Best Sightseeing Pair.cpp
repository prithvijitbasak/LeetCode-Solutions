//Editorial: https://leetcode.com/problems/best-sightseeing-pair/discuss/260850/JavaC%2B%2BPython-One-Pass-O(1)-space, https://youtu.be/acZLDtayXlU
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans=0,maxtillnow=0,n=values.size();
        for(int i=0;i<n;i++)
        {
            ans=max(ans,maxtillnow+values[i]-i);
            maxtillnow=max(maxtillnow,values[i]+i);
        }
        return ans;
    }
};
