//Approach 1: Using bottom-up dp. TC: O(n) SC: O(n)
//Editorial: https://leetcode.com/problems/min-cost-climbing-stairs/discuss/873158/4-variantseasy-understandingdprecursion
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n);
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<n;i++)
        {
            dp[i]=min(dp[i-1],dp[i-2])+cost[i];
        }
        // for(int i=0;i<n;i++)  cout<<dp[i]<<" ";
        return min(dp[n-2],dp[n-1]);
    }
};
//Approach 2: using Bottom-up dp with space optimisation TC: O(n) SC: O(1)
//Editorial: https://leetcode.com/problems/min-cost-climbing-stairs/discuss/144682/3-Lines-Java-Solution-O(1)-space/222717
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int twostepsbefore=cost[0];
        int onestepbefore=cost[1];
        int n=cost.size();
        for(int i=2;i<n;i++)
        {
            int curr=min(twostepsbefore,onestepbefore)+cost[i];
            twostepsbefore=onestepbefore;
            onestepbefore=curr;
        }
        return min(twostepsbefore,onestepbefore);
    }
};
