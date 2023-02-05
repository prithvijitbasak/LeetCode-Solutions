//Editorial: https://youtu.be/Wg0Z58YjHls
class Solution {
public:
    typedef long long ll;
    set<char> st={'a','e','i','o','u'};
    bool check(string s)
    {
        ll n=s.size();
        if(st.find(s[0])!=st.end() and st.find(s[n-1])!=st.end())
            return true;
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        ll n=words.size();
        ll m=queries.size();
        vector<int> ans(m);
        vector<ll> pre(n+1,0);
        for(ll i=0;i<n;i++)
        {
            if(check(words[i]))
                pre[i+1]=pre[i]+1;
            else
                pre[i+1]=pre[i];
        }
        for(ll i=0;i<queries.size();i++)
        {
            ll l=queries[i][0];
            ll r=queries[i][1];
            ans[i]=(pre[r+1]-pre[l]);
        }
        return ans;
    }
};
