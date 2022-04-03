//Editorial: Just count the number of time a player loses in hashmap abd find the required answer.
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        map<int,int> mp;
        set<int> st;
        for(auto it:matches)
        {
            mp[it[0]]=0;
            mp[it[1]]=0;
        }
        for(auto it:matches)
            mp[it[1]]+=1;
        for(auto it:mp)
        {
            if(it.second==0)
                ans[0].push_back(it.first);
            if(it.second==1)
                ans[1].push_back(it.first);
        }
        return ans;
    }
};
