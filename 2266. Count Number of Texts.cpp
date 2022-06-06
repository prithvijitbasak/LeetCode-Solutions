//Editorial: https://leetcode.com/problems/count-number-of-texts/discuss/2024229/C++-O(n)-Solution-with-Explanation
class Solution {
public:
    int mod=1e9+7;
    typedef long long ll;
    int countTexts(string s) {
        int n=s.size();
        if(n<3)
            return n;
        ll ans=1;
        vector<ll> dp1(n+1,0);
        vector<ll> dp2(n+1,0);
        dp1[0]=1;
        dp1[1]=1;
        dp1[2]=2;
        dp2[0]=1;
        dp2[1]=1;
        dp2[2]=2;
        dp2[3]=4;
        for(int i=3;i<=n;i++)
            dp1[i]=(dp1[i-1]+dp1[i-2]+dp1[i-3])%mod;
        for(int i=4;i<=n;i++)
            dp2[i]=(dp2[i-1]+dp2[i-2]+dp2[i-3]+dp2[i-4])%mod;
        int start=-1;
        int i=0;
        while(i<n-1)
        {
            while(i<n-1 and s[i]==s[i+1])
                i++;
            int len=i-start;
            if(s[i]=='7' or s[i]=='9')
                ans=(ans*dp2[len])%mod;
            else
                ans=(ans*dp1[len])%mod;
            start=i;
            i++;
        }
        return ans;
    }
};
