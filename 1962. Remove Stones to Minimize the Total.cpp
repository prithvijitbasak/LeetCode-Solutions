//Editorial: https://leetcode.com/problems/remove-stones-to-minimize-the-total/solutions/2636179/remove-stones-to-minimize-the-total/?orderBy=most_votes
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> maxh(piles.begin(),piles.end());
        int sum=accumulate(piles.begin(),piles.end(),0);
        for(int i=0;i<k;i++)
        {
            int curr=maxh.top();
            int temp=curr;
            maxh.pop();
            temp/=2;
            sum-=temp;
            maxh.push(curr-temp);
        }
        return sum;
    }
};
