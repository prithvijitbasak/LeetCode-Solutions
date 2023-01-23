//Editorial: https://youtu.be/Y7UTvogADH0 , https://leetcode.com/problems/maximum-performance-of-a-team/solutions/539687/java-c-python-priority-queue/?orderBy=most_votes
class Solution {
public:
    typedef long long ll;
    int maxPerformance(int n, vector<int>& s, vector<int>& e, int k) {
        vector<pair<ll,ll>> arr;
        for(ll i=0;i<n;i++)
            arr.push_back({e[i],s[i]});
        sort(arr.rbegin(),arr.rend());
        ll ans=INT_MIN,sum=0;
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        for(ll i=0;i<n;i++)
        {
            pq.push(arr[i].second);
            sum+=arr[i].second;
            if(pq.size()>k)
            {
                sum-=pq.top();
                pq.pop();
            }
            ans=max(ans,sum*arr[i].first);
        }
        return ans%((int)(1e9+7));
    }
};
