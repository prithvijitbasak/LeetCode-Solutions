//Editorial: https://www.geeksforgeeks.org/sieve-of-eratosthenes/
class Solution {
public:
    int countPrimes(int n) {
        vector<int> v(n+1,1);
        for(int i=2;i*i<=n;i++)
        {
            if(v[i])
            {
                for(int j=i*i;j<=n;j+=i)
                    v[j]=0;
            }
        }
        int ans=0;
        for(int i=2;i<n;i++)
        {
            if(v[i])
                ans+=1;
        }
        return ans;
    }
};
