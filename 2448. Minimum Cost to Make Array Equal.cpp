//Editorial: https://youtu.be/clHTLCrl7eM
class Solution {
public:
    typedef long long ll;
    long long minCost(vector<int>& nums, vector<int>& cost) {
        ll ans=0;
        ll n=nums.size();
        vector<pair<ll,ll>> temp; 
        for(ll i=0;i<n;i++)
            temp.push_back({nums[i],cost[i]});
        sort(temp.begin(),temp.end());
        ll sum=0;
        for(auto it:temp)
            sum+=(it.second);
        ll sz=temp.size();
        ll val;
        ll tempsum=0,i=0;
        while(tempsum<(sum+1)/2 and i<n)
        {
            tempsum+=temp[i].second;
            val=temp[i].first;
            i+=1;
        }
        for(ll i=0;i<n;i++)
        {
            if(nums[i]!=val)
            {
                ll diff=abs(nums[i]-val);
                ans+=(cost[i]*diff);
            }
        }
        return ans;
    }
};
