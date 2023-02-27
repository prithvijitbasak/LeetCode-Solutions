//Editorial: https://leetcode.com/problems/find-the-divisibility-array-of-a-string/solutions/3230950/stepwise-explanation-with-images-easy-to-understand-simple-division-rule/?orderBy=most_votes
class Solution {
public:
    typedef long long ll;
    vector<int> divisibilityArray(string word, int m) {
        ll n=word.size();
        vector<int> ans(n,0);
        ll prev=0;
        for(ll i=0;i<n;i++)
        {
            ll curr=word[i]-'0';
            ll newdiv=(prev*10)+curr;
            ll rem=newdiv%m;
            if(rem==0)
                ans[i]=1;
            prev=rem;
        }
        return ans;
    }
};
