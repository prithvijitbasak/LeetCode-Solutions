//Editorial: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/75928/Share-my-DP-solution-(By-State-Machine-Thinking), https://youtu.be/4wNXkhAky3s
//Approach 1: Using 3 arrays to memoizise the previous states. TC: O(n) SC: O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<=1)
            return 0;
        vector<int> selling(n,0),buying(n,0),cooldown(n,0);
        cooldown[0]=0;
        selling[0]=INT_MIN;
        buying[0]=-prices[0];
        for(int i=1;i<n;i++)
        {
            cooldown[i]=max(cooldown[i-1],selling[i-1]);
            buying[i]=max(buying[i-1],cooldown[i-1]-prices[i]);
            selling[i]=buying[i-1]+prices[i];
        }
        return max(cooldown[n-1],selling[n-1]);
    }
};
//Approach 2: Using state optimisation. TC: O(n) SC: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int selling=0,cooldown=0,buying=-prices[0];
        for(int i=0;i<n;i++)
        {
            int prevselling=selling;
            selling=buying+prices[i];
            buying=max(buying,cooldown-prices[i]);
            cooldown=max(cooldown,prevselling);
        }
        return max(cooldown,selling);
    }
};
