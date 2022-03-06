//Editorial: https://youtu.be/H0Yl1AlUuK8
class Solution {
public:
    int countOrders(int n) {
        long long ans=1;
        int mod=1e9+7;
        for(int i=1;i<=n;i++)
        {
            ans*=i;
            ans%=mod;
            ans*=(2*i-1);
            ans%=mod;
        }
        return ans%mod;
    }
};
