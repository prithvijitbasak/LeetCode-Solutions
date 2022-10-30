//Editorial: https://leetcode.com/problems/most-popular-video-creator/discuss/2758053/One-HashMap-No-Sorting
class Solution {
public:
    typedef long long ll;
    struct video{
        ll totalview=0;
        string maxid;
        ll maxview=0;
    };
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        unordered_map<string,video> mp;
        ll count=0;
        ll n=ids.size();
        for(ll i=0;i<n;i++)
        {
            string c=creators[i];
            if(mp.find(c)==mp.end())
            {
                mp[c]={views[i],ids[i],views[i]};
                count=max(count,mp[c].totalview);
                continue;
            }
            mp[c].totalview+=views[i];
            if((mp[c].maxid>ids[i] and mp[c].maxview==views[i]) or mp[c].maxview<views[i])
            {
                mp[c].maxid=ids[i];
                mp[c].maxview=views[i];
            }
            count=max(mp[c].totalview,count);
        }
        vector<vector<string>> ans;
        for(auto it:mp)
        {
            if(it.second.totalview==count)
                ans.push_back(vector<string> {it.first,it.second.maxid});
        }
        return ans;
    }
};
