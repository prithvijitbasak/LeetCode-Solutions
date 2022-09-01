//Editorial: https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/discuss/2492774/JavaC++Python-Explanation-with-Observations
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int ans=0;
        vector<int> last(128,0);
        for(int i=0;i<garbage.size();i++)
        {
            ans+=garbage[i].size();
            for(auto ch:garbage[i])
                last[ch]=i;
        }
        for(int i=1;i<travel.size();i++)
            travel[i]+=travel[i-1];
        for(auto it:"PGM")
        {
            if(last[it])
                ans+=travel[last[it]-1];
        }
        return ans;
    }
};
