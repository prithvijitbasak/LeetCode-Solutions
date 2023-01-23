//Editorial: https://youtu.be/Y7UTvogADH0 , https://leetcode.com/problems/maximum-subsequence-score/solutions/3082106/java-c-python-priority-queue/?orderBy=most_votes
class Solution {
public:
    typedef long long ll;
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        ll n=nums1.size();
        vector<pair<ll,ll>> arr;
        for(ll i=0;i<n;i++)
            arr.push_back({nums2[i],nums1[i]});
        sort(arr.rbegin(),arr.rend());
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        ll sum=0;
        ll ans=INT_MIN;
        for(ll i=0;i<n;i++)
        {
            pq.push(arr[i].second);
            sum+=(ll)arr[i].second;
            if(pq.size()>k)
            {
                sum-=pq.top();
                pq.pop();
            }
            if(pq.size()==k)
                ans=max(ans,sum*arr[i].first);
        }
        return ans;
    }
};
