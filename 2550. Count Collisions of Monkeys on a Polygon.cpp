//Editorial: https://youtu.be/GJymXvFnYX8
class Solution {
public:
    typedef long long ll;
    ll mod=1e9+7;
    ll binpow(ll a, ll b)
    {
        a %= mod;
        ll res = 1;
        while (b > 0) {
            if (b & 1)
                res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }
    int monkeyMove(int n) {
        ll ans=binpow(2,n)%mod;
        ans-=2;
        if(ans<0)
            ans+=mod;
        return ans;
    }
};
