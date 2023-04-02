//Editorial: https://leetcode.com/problems/successful-pairs-of-spells-and-potions/editorial
//Approach 1: Using Binary search and sorting. TC: O((m+n)logm) SC: O(logm)
class Solution {
public:
    typedef long long ll;
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        ll n=spells.size();
        ll m=potions.size();
        vector<int> ans(n);
        sort(potions.begin(),potions.end());
        ll maxpotion=potions[m-1];
        for(ll i=0;i<n;i++)
        {
            ll minpotion=ceil((1.0*success)/spells[i]);
            if(minpotion>maxpotion)
                ans[i]=0;
            else
            {
                ll idx=lower_bound(potions.begin(),potions.end(),minpotion)-potions.begin();
                ans[i]=m-idx;
            }
        }
        return ans;
    }
};

//Approach 2: Using Sorting + Two pointer. TC: O(nlogn + mlogm) SC: O(logm)
class Solution {
public:
    typedef long long ll;
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        ll n=spells.size();
        ll m=potions.size();
        vector<pair<ll,ll>> spellsidx;
        for(ll i=0;i<n;i++)
            spellsidx.push_back({spells[i],i});
        sort(spellsidx.begin(),spellsidx.end());
        sort(potions.begin(),potions.end());
        ll potionidx=m-1;
        vector<int> ans(n);
        for(auto &[spell,idx]:spellsidx)
        {
            while(potionidx>=0 and (ll)(spell*potions[potionidx])>=success)
                potionidx-=1;
            ans[idx]=m-(potionidx+1);
        }
        return ans;
    }
};
