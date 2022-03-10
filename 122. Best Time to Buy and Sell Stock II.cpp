//Editorial: https://youtu.be/K8iHi8AW1ls
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0,n=prices.size();
        for(int i=1;i<n;i++)
        {
            if(prices[i]>prices[i-1])
                ans+=prices[i]-prices[i-1];
        }
        return ans;
    }
};
