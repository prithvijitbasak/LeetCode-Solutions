//Editorial: https://leetcode.com/problems/take-gifts-from-the-richest-pile/solutions/3143722/priority-queue-very-simple-easy-to-understand-solution/?orderBy=most_votes
class Solution {
public:
    typedef long long ll;
    long long pickGifts(vector<int>& gifts, int k) {
        ll ans=0;
        priority_queue<ll> pq;
        for(auto it:gifts)
            pq.push(it);
        while(k--)
        {
            int flval=sqrt(pq.top());
            pq.pop();
            pq.push(flval);
        }
        while(!pq.empty())
        {
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};
