//Editorial: https://leetcode.com/problems/minimum-number-of-refueling-stops/discuss/1267000/C++-3-approaches-FULL-STORY-LIKE-Explanation-(-O(n2)-Dp-greater-O(n)-dp-greater-O(nlogn)-using-max-heap-)
//Approach 1: Using 2D DP. TC: O(n^2) SC: O(n^2)
class Solution {
public:
    typedef long long ll;
    int minRefuelStops(int target, int startfuel, vector<vector<int>>& stations) {
        int n=stations.size();
        vector<vector<ll>> dp(n+1,vector<ll> (n+1,0));
        for(int i=0;i<=n;i++)
            dp[i][0]=startfuel;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                dp[i][j]=dp[i-1][j];
                if(dp[i-1][j-1]>=stations[i-1][0])
                    dp[i][j]=max(dp[i][j],dp[i-1][j-1]+stations[i-1][1]);
            }
        }
        for(int j=0;j<=n;j++)
        {
            if(dp[n][j]>=target)
                return j;
        }
        return -1;
    }
};
//Approach 2: Using max-heap. TC: O(nlogn) SC: O(n)
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int n=stations.size();
        int curr=startFuel;
        int ans=0;
        int i=0;
        while(curr<target)
        {
            while(i<n and curr>=stations[i][0])
            {
                pq.push(stations[i][1]);
                i++;
            }
            if(pq.empty())
                return -1;
            curr+=pq.top();
            pq.pop();
            ans+=1;
        }
        return ans;
    }
};
