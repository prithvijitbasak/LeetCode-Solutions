//Editorial: https://youtu.be/03XRhhrUPKY , https://leetcode.com/problems/rearranging-fruits/solutions/3143917/java-c-python-two-ways-to-swap/?orderBy=most_votes
class Solution {
public:
    typedef long long ll;
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        ll ans=0;
        map<ll,ll> mp;
        for(auto it:basket1)
            mp[it]+=1;
        for(auto it:basket2)
            mp[it]-=1;
        ll mn=mp.begin()->first;
        vector<ll> valids;
        for(auto it:mp)
        {
            if(it.second&1)
                return -1;
            for(ll i=0;i<abs(it.second)/2;i++)
                valids.push_back(it.first);
        }
        for(ll i=0;i<valids.size()/2;i++)
            ans+=min(valids[i],2*mn);
        return ans;
    }
};
