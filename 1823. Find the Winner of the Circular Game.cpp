//Approach 1: Using queue to simulate the operation. TC: O(n) SC: O(n)
//Editorial: https://leetcode.com/problems/find-the-winner-of-the-circular-game/discuss/1152594/C%2B%2B-oror-QUEUE-oror-SELF-EXPALANATORY
class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i=1;i<=n;i++)
            q.push(i);
        while(q.size()>1)
        {
            int temp=k-1;
            while(temp--)
            {
                int val=q.front();
                q.pop();
                q.push(val);
            }
            q.pop();
        }
        return q.front();
    }
};
//Approach 2: Using iterative way to solve this. TC: O(n) SC: O(1)
//Editorial: https://leetcode.com/problems/find-the-winner-of-the-circular-game/discuss/1601186/C%2B%2B-oror-3-Approach-oror-Easy-Understanding
class Solution {
public:
    int findTheWinner(int n, int k) {
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans=(ans+k)%i;
        }
        return ans+1;
    }
};
