//Editorial: https://youtu.be/u0n-6zBnohY
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> maxh;
        int mn=INT_MAX;
        for(auto it:nums)
        {
            if(it&1)
                it*=2;
            mn=min(mn,it);
            maxh.push(it);
        }
        int ans=INT_MAX;
        while(maxh.top()%2==0)
        {
            int mx=maxh.top();
            maxh.pop();
            ans=min(ans,mx-mn);
            mn=min(mn,mx/2);
            maxh.push(mx/2);
        }
        ans=min(ans,maxh.top()-mn);
        return ans;
    }
};
