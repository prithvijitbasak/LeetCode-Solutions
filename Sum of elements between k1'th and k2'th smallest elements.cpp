//Editorial: https://www.geeksforgeeks.org/sum-elements-k1th-k2th-smallest-elements/
class Solution{
    public:
    typedef long long ll;
    long long sumBetweenTwoKth( long long arr[], long long n, long long k1, long long k2)
    {
        priority_queue<ll> pq;
        for(ll i=0;i<n;i++)
        {
            pq.push(arr[i]);
            if(pq.size()>k1)
              pq.pop();
        }
        ll start=pq.top();
        while(!pq.empty())
          pq.pop();
        for(ll i=0;i<n;i++)
        {
            pq.push(arr[i]);
            if(pq.size()>k2)
              pq.pop();
        }
        ll end=pq.top();
        ll ans=0;
        for(ll i=0;i<n;i++)
        {
            if(arr[i]>start and arr[i]<end)
              ans+=arr[i];
        }
        return ans;
    }
};
