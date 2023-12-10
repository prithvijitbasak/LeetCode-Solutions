//Editorial: https://leetcode.com/problems/double-modular-exponentiation/solutions/4384819/mastering-modular-exponentiation-beginner-s-guide/
class Solution {
public:
    typedef long long ll;
    // this is a modular binary exponentiation only with a mod val
    ll binpow(ll a, ll b, ll mod)
    {
        a %= mod;
        ll res = 1;
        while(b > 0)
        {
            if(b & 1)
                res = res * a % mod;
            a = a * a % mod;
            b >>= 1;
        }
        return res;
    }
    vector<int> getGoodIndices(vector<vector<int>>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            int a=nums[i][0], b=nums[i][1], c=nums[i][2], m=nums[i][3];
            int fval = binpow(a, b, 10);
            int sval = binpow(fval, c, m);
            if(sval == target)
                ans.push_back(i);
        }
        return ans;
    }
};
