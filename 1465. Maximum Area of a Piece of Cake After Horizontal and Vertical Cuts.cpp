//Editorial: https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/discuss/661995/Do-you-like-visual-explanation-You-got-it.-:-)-With-2-code-variations.
class Solution {
public:
    typedef long long ll;
    int maxArea(int h, int w, vector<int>& hor, vector<int>& ver) {
        ll mod=1e9+7;
        sort(hor.begin(),hor.end());
        sort(ver.begin(),ver.end());
        vector<int> b={hor[0]};
        int nh=hor.size();
        int nw=ver.size();
        for(int i=1;i<nh;i++)
            b.push_back(hor[i]-hor[i-1]);
        b.push_back(h-hor[nh-1]);
        vector<int> l={ver[0]};
        for(int i=1;i<nw;i++)
            l.push_back(ver[i]-ver[i-1]);
        l.push_back(w-ver[nw-1]);
        ll x=*max_element(b.begin(),b.end());
        ll y=*max_element(l.begin(),l.end());
        return (x*y)%mod;
    }
};
