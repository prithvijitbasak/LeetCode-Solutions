//Editorial: https://leetcode.com/problems/substring-xor-queries/solutions/3174092/o-32-n-hash-map-solution/?orderBy=most_votes
class Solution {
public:
    typedef long long ll;
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        map<ll,pair<int,int>> mp;
        ll n=s.size();
        for(ll i=0;i<n;i++)
        {
            if(s[i]=='0')
            {
                if(mp.find(0)==mp.end())
                    mp[0]={i,i};
                continue;
            }
            ll val=0;
            for(ll j=i;j<=min(i+32,n-1);j++)
            {
                val=(val<<1)+(s[j]-'0');
                if(mp.find(val)==mp.end())
                    mp[val]={i,j};
            }
        }
        vector<vector<int>> ans;
        for(ll i=0;i<queries.size();i++)
        {
            ll f=queries[i][0];
            ll s=queries[i][1];
            ll val=f^s;
            if(mp.find(val)!=mp.end())
                ans.push_back({mp[val].first,mp[val].second});
            else
                ans.push_back({-1,-1});
        }
        return ans;
    }
};
